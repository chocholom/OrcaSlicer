// BBLNetworkPlugin.cpp - Minimal stub (DLL not available)
//
// All methods return failure/empty/no-op since the proprietary BBL network
// DLL is not shipped with this build.

#include "BBLNetworkPlugin.hpp"

namespace Slic3r {

std::vector<NetworkLibraryVersionInfo> get_all_available_versions() { return {}; }

// ============================================================================
// Singleton Implementation
// ============================================================================

BBLNetworkPlugin* BBLNetworkPlugin::s_instance = nullptr;

BBLNetworkPlugin& BBLNetworkPlugin::instance()
{
    static BBLNetworkPlugin s_default;
    return s_default;
}

void BBLNetworkPlugin::shutdown() {}

BBLNetworkPlugin::BBLNetworkPlugin() = default;
BBLNetworkPlugin::~BBLNetworkPlugin() = default;

// ============================================================================
// Module Lifecycle
// ============================================================================

int BBLNetworkPlugin::initialize(bool /*using_backup*/, const std::string& /*version*/)
{
    return -1;
}

int BBLNetworkPlugin::unload()
{
    return 0;
}

bool BBLNetworkPlugin::is_loaded() const
{
    return false;
}

std::string BBLNetworkPlugin::get_version() const
{
    return "00.00.00.00";
}

// ============================================================================
// Agent Lifecycle
// ============================================================================

void* BBLNetworkPlugin::create_agent(const std::string& /*log_dir*/)
{
    return nullptr;
}

int BBLNetworkPlugin::destroy_agent()
{
    return 0;
}

// ============================================================================
// DLL Module Accessors
// ============================================================================

#if defined(_MSC_VER) || defined(_WIN32)
HMODULE BBLNetworkPlugin::get_source_module()
#else
void* BBLNetworkPlugin::get_source_module()
#endif
{
    return nullptr;
}

void* BBLNetworkPlugin::get_function(const char* /*name*/)
{
    return nullptr;
}

// ============================================================================
// Utility Methods
// ============================================================================

std::string BBLNetworkPlugin::get_libpath_in_current_directory(const std::string& /*library_name*/)
{
    return "";
}

std::string BBLNetworkPlugin::get_versioned_library_path(const std::string& /*version*/)
{
    return "";
}

bool BBLNetworkPlugin::versioned_library_exists(const std::string& /*version*/)
{
    return false;
}

bool BBLNetworkPlugin::legacy_library_exists()
{
    return false;
}

void BBLNetworkPlugin::remove_legacy_library() {}

std::vector<std::string> BBLNetworkPlugin::scan_plugin_versions()
{
    return {};
}

// ============================================================================
// Error Handling
// ============================================================================

void BBLNetworkPlugin::clear_load_error()
{
    m_load_error = NetworkLibraryLoadError{};
}

void BBLNetworkPlugin::set_load_error(const std::string& message,
                                       const std::string& technical_details,
                                       const std::string& attempted_path)
{
    m_load_error.has_error = true;
    m_load_error.message = message;
    m_load_error.technical_details = technical_details;
    m_load_error.attempted_path = attempted_path;
}

// ============================================================================
// Legacy Helper
// ============================================================================

PrintParams_Legacy BBLNetworkPlugin::as_legacy(PrintParams& param)
{
    PrintParams_Legacy l;
    l.dev_id = std::move(param.dev_id);
    l.task_name = std::move(param.task_name);
    l.project_name = std::move(param.project_name);
    l.preset_name = std::move(param.preset_name);
    l.filename = std::move(param.filename);
    l.config_filename = std::move(param.config_filename);
    l.plate_index = param.plate_index;
    l.ftp_folder = std::move(param.ftp_folder);
    l.ftp_file = std::move(param.ftp_file);
    l.ftp_file_md5 = std::move(param.ftp_file_md5);
    l.ams_mapping = std::move(param.ams_mapping);
    l.ams_mapping_info = std::move(param.ams_mapping_info);
    l.connection_type = std::move(param.connection_type);
    l.comments = std::move(param.comments);
    l.origin_profile_id = param.origin_profile_id;
    l.stl_design_id = param.stl_design_id;
    l.origin_model_id = std::move(param.origin_model_id);
    l.print_type = std::move(param.print_type);
    l.dst_file = std::move(param.dst_file);
    l.dev_name = std::move(param.dev_name);
    l.dev_ip = std::move(param.dev_ip);
    l.use_ssl_for_ftp = param.use_ssl_for_ftp;
    l.use_ssl_for_mqtt = param.use_ssl_for_mqtt;
    l.username = std::move(param.username);
    l.password = std::move(param.password);
    l.task_bed_leveling = param.task_bed_leveling;
    l.task_flow_cali = param.task_flow_cali;
    l.task_vibration_cali = param.task_vibration_cali;
    l.task_layer_inspect = param.task_layer_inspect;
    l.task_record_timelapse = param.task_record_timelapse;
    l.task_use_ams = param.task_use_ams;
    l.task_bed_type = std::move(param.task_bed_type);
    l.extra_options = std::move(param.extra_options);
    return l;
}

// ============================================================================
// Function Pointer Loading (no-ops in stub)
// ============================================================================

void BBLNetworkPlugin::load_all_function_pointers() {}
void BBLNetworkPlugin::clear_all_function_pointers() {}

} // namespace Slic3r
