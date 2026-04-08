// BBLCloudServiceAgent.cpp - Minimal stub (DLL not available)
//
// All methods return failure/empty since the proprietary BBL network
// DLL is not shipped with this build.

#include "BBLCloudServiceAgent.hpp"

namespace Slic3r {

BBLCloudServiceAgent::BBLCloudServiceAgent() = default;
BBLCloudServiceAgent::~BBLCloudServiceAgent() = default;

// Lifecycle
int BBLCloudServiceAgent::init_log() { return -1; }
int BBLCloudServiceAgent::set_config_dir(std::string /*config_dir*/) { return -1; }
int BBLCloudServiceAgent::set_cert_file(std::string /*folder*/, std::string /*filename*/) { return -1; }
int BBLCloudServiceAgent::set_country_code(std::string /*country_code*/) { return -1; }
int BBLCloudServiceAgent::start() { return -1; }

// User Session Management
int BBLCloudServiceAgent::change_user(std::string /*user_info*/) { return -1; }
bool BBLCloudServiceAgent::is_user_login() { return false; }
int BBLCloudServiceAgent::user_logout(bool /*request*/) { return -1; }
std::string BBLCloudServiceAgent::get_user_id() { return ""; }
std::string BBLCloudServiceAgent::get_user_name() { return ""; }
std::string BBLCloudServiceAgent::get_user_avatar() { return ""; }
std::string BBLCloudServiceAgent::get_user_nickname() { return ""; }

// Login UI Support
std::string BBLCloudServiceAgent::build_login_cmd() { return ""; }
std::string BBLCloudServiceAgent::build_logout_cmd() { return ""; }
std::string BBLCloudServiceAgent::build_login_info() { return ""; }

// Token Access
std::string BBLCloudServiceAgent::get_access_token() const { return ""; }
std::string BBLCloudServiceAgent::get_refresh_token() const { return ""; }
bool BBLCloudServiceAgent::ensure_token_fresh(const std::string& /*reason*/) { return false; }

// Auth Callbacks
int BBLCloudServiceAgent::set_on_user_login_fn(OnUserLoginFn /*fn*/) { return -1; }

// Server Connectivity
std::string BBLCloudServiceAgent::get_cloud_service_host() { return ""; }
std::string BBLCloudServiceAgent::get_cloud_login_url(const std::string& /*language*/) { return ""; }
int BBLCloudServiceAgent::connect_server() { return -1; }
bool BBLCloudServiceAgent::is_server_connected() { return false; }
int BBLCloudServiceAgent::refresh_connection() { return -1; }
int BBLCloudServiceAgent::start_subscribe(std::string /*module*/) { return -1; }
int BBLCloudServiceAgent::stop_subscribe(std::string /*module*/) { return -1; }
int BBLCloudServiceAgent::add_subscribe(std::vector<std::string> /*dev_list*/) { return -1; }
int BBLCloudServiceAgent::del_subscribe(std::vector<std::string> /*dev_list*/) { return -1; }
void BBLCloudServiceAgent::enable_multi_machine(bool /*enable*/) {}

// Settings Synchronization
int BBLCloudServiceAgent::get_user_presets(std::map<std::string, std::map<std::string, std::string>>* /*user_presets*/) { return -1; }
std::string BBLCloudServiceAgent::request_setting_id(std::string /*name*/, std::map<std::string, std::string>* /*values_map*/, unsigned int* /*http_code*/) { return ""; }
int BBLCloudServiceAgent::put_setting(std::string /*setting_id*/, std::string /*name*/, std::map<std::string, std::string>* /*values_map*/, unsigned int* /*http_code*/) { return -1; }
int BBLCloudServiceAgent::get_setting_list(std::string /*bundle_version*/, ProgressFn /*pro_fn*/, WasCancelledFn /*cancel_fn*/) { return -1; }
int BBLCloudServiceAgent::get_setting_list2(std::string /*bundle_version*/, CheckFn /*chk_fn*/, ProgressFn /*pro_fn*/, WasCancelledFn /*cancel_fn*/) { return -1; }
int BBLCloudServiceAgent::delete_setting(std::string /*setting_id*/) { return -1; }

// Cloud User Services
int BBLCloudServiceAgent::get_my_message(int /*type*/, int /*after*/, int /*limit*/, unsigned int* /*http_code*/, std::string* /*http_body*/) { return -1; }
int BBLCloudServiceAgent::check_user_task_report(int* /*task_id*/, bool* /*printable*/) { return -1; }
int BBLCloudServiceAgent::get_user_print_info(unsigned int* /*http_code*/, std::string* /*http_body*/) { return -1; }
int BBLCloudServiceAgent::get_user_tasks(TaskQueryParams /*params*/, std::string* /*http_body*/) { return -1; }
int BBLCloudServiceAgent::get_printer_firmware(std::string /*dev_id*/, unsigned* /*http_code*/, std::string* /*http_body*/) { return -1; }
int BBLCloudServiceAgent::get_task_plate_index(std::string /*task_id*/, int* /*plate_index*/) { return -1; }
int BBLCloudServiceAgent::get_user_info(int* /*identifier*/) { return -1; }
int BBLCloudServiceAgent::get_subtask_info(std::string /*subtask_id*/, std::string* /*task_json*/, unsigned int* /*http_code*/, std::string* /*http_body*/) { return -1; }
int BBLCloudServiceAgent::get_slice_info(std::string /*project_id*/, std::string /*profile_id*/, int /*plate_index*/, std::string* /*slice_json*/) { return -1; }
int BBLCloudServiceAgent::query_bind_status(std::vector<std::string> /*query_list*/, unsigned int* /*http_code*/, std::string* /*http_body*/) { return -1; }
int BBLCloudServiceAgent::modify_printer_name(std::string /*dev_id*/, std::string /*dev_name*/) { return -1; }

// Model Mall & Publishing
int BBLCloudServiceAgent::get_camera_url(std::string /*dev_id*/, std::function<void(std::string)> /*callback*/) { return -1; }
int BBLCloudServiceAgent::get_design_staffpick(int /*offset*/, int /*limit*/, std::function<void(std::string)> /*callback*/) { return -1; }
int BBLCloudServiceAgent::start_publish(PublishParams /*params*/, OnUpdateStatusFn /*update_fn*/, WasCancelledFn /*cancel_fn*/, std::string* /*out*/) { return -1; }
int BBLCloudServiceAgent::get_model_publish_url(std::string* /*url*/) { return -1; }
int BBLCloudServiceAgent::get_subtask(BBLModelTask* /*task*/, OnGetSubTaskFn /*getsub_fn*/) { return -1; }
int BBLCloudServiceAgent::get_model_mall_home_url(std::string* /*url*/) { return -1; }
int BBLCloudServiceAgent::get_model_mall_detail_url(std::string* /*url*/, std::string /*id*/) { return -1; }
int BBLCloudServiceAgent::get_my_profile(std::string /*token*/, unsigned int* /*http_code*/, std::string* /*http_body*/) { return -1; }

// Analytics & Tracking
int BBLCloudServiceAgent::track_enable(bool enable) { m_enable_track = enable; return -1; }
int BBLCloudServiceAgent::track_remove_files() { return -1; }
int BBLCloudServiceAgent::track_event(std::string /*evt_key*/, std::string /*content*/) { return -1; }
int BBLCloudServiceAgent::track_header(std::string /*header*/) { return -1; }
int BBLCloudServiceAgent::track_update_property(std::string /*name*/, std::string /*value*/, std::string /*type*/) { return -1; }
int BBLCloudServiceAgent::track_get_property(std::string /*name*/, std::string& /*value*/, std::string /*type*/) { return -1; }
bool BBLCloudServiceAgent::get_track_enable() { return m_enable_track; }

// Ratings & Reviews
int BBLCloudServiceAgent::put_model_mall_rating(int /*design_id*/, int /*score*/, std::string /*content*/, std::vector<std::string> /*images*/, unsigned int& /*http_code*/, std::string& /*http_error*/) { return -1; }
int BBLCloudServiceAgent::get_oss_config(std::string& /*config*/, std::string /*country_code*/, unsigned int& /*http_code*/, std::string& /*http_error*/) { return -1; }
int BBLCloudServiceAgent::put_rating_picture_oss(std::string& /*config*/, std::string& /*pic_oss_path*/, std::string /*model_id*/, int /*profile_id*/, unsigned int& /*http_code*/, std::string& /*http_error*/) { return -1; }
int BBLCloudServiceAgent::get_model_mall_rating_result(int /*job_id*/, std::string& /*rating_result*/, unsigned int& /*http_code*/, std::string& /*http_error*/) { return -1; }

// Extra Features
int BBLCloudServiceAgent::set_extra_http_header(std::map<std::string, std::string> /*extra_headers*/) { return -1; }
std::string BBLCloudServiceAgent::get_studio_info_url() { return ""; }
int BBLCloudServiceAgent::get_mw_user_preference(std::function<void(std::string)> /*callback*/) { return -1; }
int BBLCloudServiceAgent::get_mw_user_4ulist(int /*seed*/, int /*limit*/, std::function<void(std::string)> /*callback*/) { return -1; }
std::string BBLCloudServiceAgent::get_version() { return ""; }

// Cloud Callbacks
int BBLCloudServiceAgent::set_on_server_connected_fn(OnServerConnectedFn /*fn*/) { return -1; }
int BBLCloudServiceAgent::set_on_http_error_fn(OnHttpErrorFn /*fn*/) { return -1; }
int BBLCloudServiceAgent::set_get_country_code_fn(GetCountryCodeFn /*fn*/) { return -1; }
int BBLCloudServiceAgent::set_queue_on_main_fn(QueueOnMainFn /*fn*/) { return -1; }

} // namespace Slic3r
