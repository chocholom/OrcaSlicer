# De-Bambu Audit & Cleanup of OrcaSlicer

Date: 2026-04-08
Base: OrcaSlicer main branch (SoftFever/OrcaSlicer)
Goal: Build a binary with zero ability to communicate with Chinese cloud services, zero automatic phone-home, and only Prusa Core One+ / PrusaConnect support.

## Background

OrcaSlicer descends from Slic3r -> PrusaSlicer -> BambuStudio. It carries deep integration with Bambu Lab's proprietary cloud services, including a closed-source DLL plugin (`libbambu_networking.dylib`) loaded at runtime that cannot be audited. The codebase also includes support for multiple Chinese printer manufacturers (Creality, Qidi, Flashforge, Elegoo, Snapmaker, MKS) and several phone-home mechanisms.
I pay a respect to the maintainers of OrcaSLicer as there are some really nice features like z antialiasing that aren't available for other slicers. BUT I'm really sorry as I'm unable to pay my privacy for it. This version can run fully offline all the network calls are done based on user action like "send to printer". The small discomfort - like to build the version myself and won't be informed within the app when OrcaSLicer new version is released is something I'm able to accept.

---

## 1. Proprietary Binary Plugin (libbambu_networking)

### What was there
- `BBLNetworkPlugin.cpp/hpp` — singleton that dynamically loads `libbambu_networking.{dll,dylib,so}` at runtime via `dlopen`/`LoadLibrary`
- 100+ function pointers resolved from the DLL: MQTT messaging, cloud auth, device binding, print jobs, telemetry tracking, AMS sync
- The DLL is **closed-source**, downloaded from Bambu servers, version-locked (`02.03.00.62` etc.)
- Cannot be audited, cannot be built from source

### How treated
- `BBLNetworkPlugin.cpp` gutted to stub: `is_loaded()` returns false, `create_agent()` returns nullptr, all methods are no-ops
- `BBLCloudServiceAgent.cpp` gutted to stub: all 60+ ICloudServiceAgent methods return -1/false/""
- `BBLPrinterAgent.cpp` gutted to stub: all IPrinterAgent methods return -1/false/""
- `bambu_networking.hpp` kept as-is (pure declarations — macros, typedefs, structs, enums — referenced by 50+ files, no implementation)
- `get_all_available_versions()` free function added as stub returning empty vector
- String literals like `"bambu_networking"` remain in the binary from header macros but are dead code — nothing loads or resolves them

---

## 2. Chinese Manufacturer Print Hosts

### What was there
- `CrealityPrint.cpp/hpp` — Creality cloud print host
- `Flashforge.cpp/hpp` — Flashforge print host
- `ElegooLink.cpp/hpp` — Elegoo print host (extended OctoPrint with WebSocket)
- `MKS.cpp/hpp` — MKS/Mainsail print host
- `ESP3D.cpp/hpp` — ESP3D WiFi firmware print host
- `QidiPrinterAgent.cpp/hpp` — Qidi printer agent (extended Moonraker)
- `SnapmakerPrinterAgent.cpp/hpp` — Snapmaker printer agent (extended Moonraker)
- All registered in `PrintHostType` enum and `PrintHost::get_print_host()` factory
- Qidi/Snapmaker/BBL agents registered in `NetworkAgentFactory::register_all_agents()`

### How treated
- All 7 source file pairs commented out in `src/slic3r/CMakeLists.txt` (not compiled)
- `PrintHostType` enum stripped: removed `htMKS`, `htESP3D`, `htCrealityPrint`, `htFlashforge`, `htElegooLink`
- `PrintHost.cpp` factory: removed switch cases and #includes for all 5
- `PrintConfig.cpp`: removed enum key mappings and dropdown entries
- `NetworkAgentFactory.cpp`: removed registration of QidiPrinterAgent, SnapmakerPrinterAgent, BBLPrinterAgent
- Dangling references fixed in `Plater.cpp` (ElegooLink default) and `PhysicalPrinterDialog.cpp` (Flashforge field hiding)
- Source files left on disk but not compiled

---

## 3. Manufacturer Profiles

### What was there
- 128 manufacturer profile directories under `resources/profiles/`
- BBL.json (279KB), Creality.json (75KB), Qidi.json (232KB), Flashforge.json (98KB), Elegoo.json (65KB), Snapmaker.json (62KB), plus 60+ other brands

### How treated
- All deleted except `Prusa/`, `Prusa.json`, `Custom/`, `Custom.json`
- Built binary contains only Prusa printer definitions

---

## 4. BBL GUI Components

### What was there
- `BBLStatusBar.cpp/hpp` — custom status bar for Bambu operations
- `BBLStatusBarBind.cpp/hpp` — status bar for device binding
- `BBLStatusBarSend.cpp/hpp` — status bar for file transfer
- `BBLStatusBarPrint.cpp/hpp` — status bar for print jobs
- `BBLTopbar.cpp/hpp` — custom toolbar with Bambu branding
- `AMSMaterialsSetting.cpp/hpp` — Bambu AMS filament configuration
- `AMSSetting.cpp/hpp` — AMS general settings
- `AmsMappingPopup.cpp/hpp` — AMS slot mapping dialog (11 classes)
- `AmsWidgets.cpp/hpp` — AMS data model
- `Widgets/AMSControl.cpp/hpp` — AMS control widget (~50 methods)
- `Widgets/AMSItem.cpp/hpp` — AMS item widget (15 classes, 18 events)
- `gstbambusrc.c/h` — GStreamer plugin for Bambu video streaming

### How treated
- All .cpp files gutted to minimal stubs (empty method bodies, wxDEFINE_EVENT preserved)
- All .hpp files kept as-is (57 files include DeviceManager.hpp which includes AMS types)
- gstbambusrc.c commented out from CMakeLists (not compiled)
- DeviceManager.hpp/cpp kept as-is (too deeply wired — 57 includers, no interface to stub against)
- `is_bbl_vendor()` checks throughout GUI remain but return false for Prusa printers

---

## 5. Telemetry & Phone-Home

### What was there

| Mechanism | Endpoint | Trigger |
|-----------|----------|---------|
| System info dialog | `files.bambu-lab.com/wp-json/v1/ps` | Opt-in dialog (collects CPU, RAM, GPU, MAC hash, OS) |
| Version check | `check-version.orcaslicer.com/latest` | Automatic at startup |
| Profile sync | `api.github.com/repos/OrcaSlicer/orcaslicer-profiles/releases/tags` | Automatic background thread |
| HMS queries | `e.bambulab.com/GetVersion.php`, `/query.php`, `/GetActionImage.php` | When Bambu printer connected |
| Tracking beacon | `e.bambulab.com/t?c=l3T7caKGeNt3omA9` | In warning dialog |
| Bambu cloud API | `api.bambulab.com`, `api.bambulab.cn` + dev/qa/pre variants | When user logs into Bambu account |
| MakerWorld | `makerworld.com` | Model browsing |
| Orca cloud | `xxx.orcaslicer.com/api/v1/sync/{pull,push}` | Background sync (placeholder URLs) |
| Ping test | `www.amazon.com`, `www.apple.com`, `www.bambulab.com` | Disabled (early return) but code present |
| HTTP headers | `X-BBL-OS-Type`, `X-Orca-Ts`, `X-Orca-Sig` | Attached to version check requests |
| Hardware fingerprint | MD5(MAC address) on Win/Linux, IOKit UUID on macOS | Included in telemetry payload |

### How treated

| Mechanism | Fix |
|-----------|-----|
| System info dialog | `SEND_SYSTEM_INFO_URL` set to `""`, `show_send_system_info_dialog_if_needed()` returns immediately |
| Version check | `VERSION_CHECK_URL` set to `""`, `check_new_version_sf()` returns immediately |
| Profile sync | `PROFILE_UPDATE_URL` set to `""`, `PresetUpdater::sync()` returns immediately, `config_update()` returns `R_NOOP` |
| HMS queries | `get_hms_host()` returns `""`, HMS.cpp checks for empty host and bails out |
| Tracking beacon | URL replaced with `""` |
| Bambu cloud API | All URLs in `get_http_url()` and `get_model_http_url()` replaced with `""` |
| Orca cloud | `ORCA_DEFAULT_API_URL` and `ORCA_DEFAULT_AUTH_URL` set to `""` |
| Ping test | Already disabled (early return), left as-is |
| HTTP headers | `get_extra_header()` returns empty map |
| HMAC signing | `maybe_attach_updater_signature()` returns immediately |
| `preset_updater->sync()` call in OnInit | Commented out |

---

## 6. Runtime Code Execution

### What was there
- `DownloadAndInstallWV2RT()` in `WebView.cpp` — downloads WebView2 runtime from `go.microsoft.com`, saves to temp, executes with `ShellExecuteExW()` (Windows only)
- GCode post-processor (`PostProcessor.cpp`) — executes user-configured scripts (standard slicer feature)

### How treated
- `DownloadAndInstallWV2RT()` neutered with early `return 2;` (download-failed code)
- Post-processor left as-is (user-configured, standard feature)

---

## 7. Embedded Browser (wxWebView)

### What was there
- Full embedded browser (WebKit on macOS, Chromium on Windows, WebKit2GTK on Linux)
- `RunScript()` JavaScript execution capability
- `WebViewDialog`, `PrinterWebView` classes

### How treated
- Left as-is — currently loads only local HTML from resources directory (`file://`)
- No external URL loading detected in code paths
- Risk: if navigation to external URLs were enabled, could execute arbitrary JS

---

## 8. What Remains in the Binary

### Active network code (user-initiated only)
- `connect.prusa3d.com` — PrusaConnect (your use case)
- `api.simplyprint.io` — SimplyPrint cloud printing
- `app.obico.io` — Obico remote monitoring
- OctoPrint, Duet, Repetier, FlashAir, AstroBox — user-configured printer hosts

### Dead string literals (in binary but never called)
- `bambu_networking` / `libbambu_networking.dylib` — macro expansions, nothing loads them
- `https://%1%/GetVersion.php` etc. — HMS URL templates, host is `""`, early-return prevents calls
- `status.bambulab.com` / `.cn` — status page link strings
- `wiki.bambulab.com/*` — help/calibration documentation links (open in browser on user click)
- `www.bambulab.com/policies/privacy` — privacy policy link string
- `http://schemas.bambulab.com/package/2021/*` — 3MF XML namespace URIs (file format identifiers, never fetched)

### Zero automatic network calls
Every remaining HTTP call requires explicit user action (clicking Send to Printer, Upload, or a help link).

---

## 9. Build Verification

```
Binary: OrcaSlicer/build/arm64/src/Debug/OrcaSlicer.app/Contents/MacOS/OrcaSlicer
Size:   354 MB (Debug, arm64)
Type:   Mach-O 64-bit executable arm64
Build:  655/655 targets, zero errors, warnings only (pre-existing)
```

Verified via `strings` on the binary:
- Zero `api.bambulab.com` URLs
- Zero `check-version.orcaslicer.com` URLs
- Zero `files.bambu-lab.com` URLs
- Zero `e.bambulab.com/t?` tracking URLs
- Only profiles: Prusa + Custom
