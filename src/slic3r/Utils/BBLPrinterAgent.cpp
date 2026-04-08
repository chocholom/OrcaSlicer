// BBLPrinterAgent.cpp - Minimal stub (DLL not available)
//
// All methods return failure/empty since the proprietary BBL network
// DLL is not shipped with this build.

#include "BBLPrinterAgent.hpp"
#include "NetworkAgentFactory.hpp"

namespace Slic3r {

BBLPrinterAgent::BBLPrinterAgent() = default;
BBLPrinterAgent::~BBLPrinterAgent() = default;

void BBLPrinterAgent::set_cloud_agent(std::shared_ptr<ICloudServiceAgent> cloud)
{
    m_cloud_agent = cloud;
}

// Communication
int BBLPrinterAgent::send_message(std::string /*dev_id*/, std::string /*json_str*/, int /*qos*/, int /*flag*/) { return -1; }
int BBLPrinterAgent::connect_printer(std::string /*dev_id*/, std::string /*dev_ip*/, std::string /*username*/, std::string /*password*/, bool /*use_ssl*/) { return -1; }
int BBLPrinterAgent::disconnect_printer() { return -1; }
int BBLPrinterAgent::send_message_to_printer(std::string /*dev_id*/, std::string /*json_str*/, int /*qos*/, int /*flag*/) { return -1; }

// Certificates
int BBLPrinterAgent::check_cert() { return -1; }
void BBLPrinterAgent::install_device_cert(std::string /*dev_id*/, bool /*lan_only*/) {}

// Discovery
bool BBLPrinterAgent::start_discovery(bool /*start*/, bool /*sending*/) { return false; }

// Binding
int BBLPrinterAgent::ping_bind(std::string /*ping_code*/) { return -1; }
int BBLPrinterAgent::bind_detect(std::string /*dev_ip*/, std::string /*sec_link*/, detectResult& /*detect*/) { return -1; }
int BBLPrinterAgent::bind(std::string /*dev_ip*/, std::string /*dev_id*/, std::string /*sec_link*/, std::string /*timezone*/, bool /*improved*/, OnUpdateStatusFn /*update_fn*/) { return -1; }
int BBLPrinterAgent::unbind(std::string /*dev_id*/) { return -1; }
int BBLPrinterAgent::request_bind_ticket(std::string* /*ticket*/) { return -1; }
int BBLPrinterAgent::set_server_callback(OnServerErrFn /*fn*/) { return -1; }

// Machine Selection
std::string BBLPrinterAgent::get_user_selected_machine() { return ""; }
int BBLPrinterAgent::set_user_selected_machine(std::string /*dev_id*/) { return -1; }

// Agent Information
AgentInfo BBLPrinterAgent::get_agent_info_static()
{
    return AgentInfo{BBL_PRINTER_AGENT_ID, "Bambu Lab", "", "Bambu Lab printer agent"};
}

// Print Job Operations
int BBLPrinterAgent::start_print(PrintParams /*params*/, OnUpdateStatusFn /*update_fn*/, WasCancelledFn /*cancel_fn*/, OnWaitFn /*wait_fn*/) { return -1; }
int BBLPrinterAgent::start_local_print_with_record(PrintParams /*params*/, OnUpdateStatusFn /*update_fn*/, WasCancelledFn /*cancel_fn*/, OnWaitFn /*wait_fn*/) { return -1; }
int BBLPrinterAgent::start_send_gcode_to_sdcard(PrintParams /*params*/, OnUpdateStatusFn /*update_fn*/, WasCancelledFn /*cancel_fn*/, OnWaitFn /*wait_fn*/) { return -1; }
int BBLPrinterAgent::start_local_print(PrintParams /*params*/, OnUpdateStatusFn /*update_fn*/, WasCancelledFn /*cancel_fn*/) { return -1; }
int BBLPrinterAgent::start_sdcard_print(PrintParams /*params*/, OnUpdateStatusFn /*update_fn*/, WasCancelledFn /*cancel_fn*/) { return -1; }

// Callbacks
int BBLPrinterAgent::set_on_ssdp_msg_fn(OnMsgArrivedFn /*fn*/) { return -1; }
int BBLPrinterAgent::set_on_printer_connected_fn(OnPrinterConnectedFn /*fn*/) { return -1; }
int BBLPrinterAgent::set_on_subscribe_failure_fn(GetSubscribeFailureFn /*fn*/) { return -1; }
int BBLPrinterAgent::set_on_message_fn(OnMessageFn /*fn*/) { return -1; }
int BBLPrinterAgent::set_on_user_message_fn(OnMessageFn /*fn*/) { return -1; }
int BBLPrinterAgent::set_on_local_connect_fn(OnLocalConnectedFn /*fn*/) { return -1; }
int BBLPrinterAgent::set_on_local_message_fn(OnMessageFn /*fn*/) { return -1; }
int BBLPrinterAgent::set_queue_on_main_fn(QueueOnMainFn /*fn*/) { return -1; }

// Filament
FilamentSyncMode BBLPrinterAgent::get_filament_sync_mode() const
{
    return FilamentSyncMode::subscription;
}

} // namespace Slic3r
