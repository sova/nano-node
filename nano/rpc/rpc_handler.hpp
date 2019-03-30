#pragma once

#include <boost/property_tree/ptree.hpp>
#include <functional>
#include <nano/lib/blocks.hpp>
#include <nano/node/wallet.hpp>
#include <string>

namespace nano
{
class node;
class rpc;
void error_response (std::function<void(boost::property_tree::ptree const &)> response_a, std::string const & message_a);

class rpc_handler : public std::enable_shared_from_this<nano::rpc_handler>
{
public:
	rpc_handler (nano::node &, nano::rpc &, std::string const &, std::string const &, std::function<void(boost::property_tree::ptree const &)> const &);
	void process_request ();
	void account_balance ();
	void account_block_count ();
	void account_count ();
	void account_create ();
	void account_get ();
	void account_history ();
	void account_info ();
	void account_key ();
	void account_list ();
	void account_move ();
	void account_remove ();
	void account_representative ();
	void account_representative_set ();
	void account_weight ();
	void accounts_balances ();
	void accounts_create ();
	void accounts_frontiers ();
	void accounts_pending ();
	void available_supply ();
	void block_info ();
	void block_confirm ();
	void blocks ();
	void blocks_info ();
	void block_account ();
	void block_count ();
	void block_count_type ();
	void block_create ();
	void block_hash ();
	void bootstrap ();
	void bootstrap_any ();
	void bootstrap_lazy ();
	void bootstrap_status ();
	void chain (bool = false);
	void confirmation_active ();
	void confirmation_history ();
	void confirmation_info ();
	void confirmation_quorum ();
	void delegators ();
	void delegators_count ();
	void deterministic_key ();
	void frontiers ();
	void keepalive ();
	void key_create ();
	void key_expand ();
	void ledger ();
	void mnano_to_raw (nano::uint128_t = nano::Mxrb_ratio);
	void mnano_from_raw (nano::uint128_t = nano::Mxrb_ratio);
	void node_id ();
	void node_id_delete ();
	void password_change ();
	void password_enter ();
	void password_valid (bool = false);
	void payment_begin ();
	void payment_init ();
	void payment_end ();
	void payment_wait ();
	void peers ();
	void pending ();
	void pending_exists ();
	void process ();
	void receive ();
	void receive_minimum ();
	void receive_minimum_set ();
	void representatives ();
	void representatives_online ();
	void republish ();
	void search_pending ();
	void search_pending_all ();
	void send ();
	void sign ();
	void stats ();
	void stats_clear ();
	void stop ();
	void unchecked ();
	void unchecked_clear ();
	void unchecked_get ();
	void unchecked_keys ();
	void unopened ();
	void uptime ();
	void validate_account_number ();
	void version ();
	void wallet_add ();
	void wallet_add_watch ();
	void wallet_balances ();
	void wallet_change_seed ();
	void wallet_contains ();
	void wallet_create ();
	void wallet_destroy ();
	void wallet_export ();
	void wallet_frontiers ();
	void wallet_history ();
	void wallet_info ();
	void wallet_key_valid ();
	void wallet_ledger ();
	void wallet_lock ();
	void wallet_pending ();
	void wallet_representative ();
	void wallet_representative_set ();
	void wallet_republish ();
	void wallet_work_get ();
	void work_generate ();
	void work_cancel ();
	void work_get ();
	void work_set ();
	void work_validate ();
	void work_peer_add ();
	void work_peers ();
	void work_peers_clear ();
	std::string body;
	std::string request_id;
	nano::node & node;
	nano::rpc & rpc;
	boost::property_tree::ptree request;
	std::function<void(boost::property_tree::ptree const &)> response;
	void response_errors ();
	std::error_code ec;
	boost::property_tree::ptree response_l;
	std::shared_ptr<nano::wallet> wallet_impl ();
	bool wallet_locked_impl (nano::transaction const &, std::shared_ptr<nano::wallet>);
	bool wallet_account_impl (nano::transaction const &, std::shared_ptr<nano::wallet>, nano::account const &);
	nano::account account_impl (std::string = "");
	nano::amount amount_impl ();
	std::shared_ptr<nano::block> block_impl (bool = true);
	std::shared_ptr<nano::block> block_json_impl (bool = true);
	nano::block_hash hash_impl (std::string = "hash");
	nano::amount threshold_optional_impl ();
	uint64_t work_optional_impl ();
	uint64_t count_impl ();
	uint64_t count_optional_impl (uint64_t = std::numeric_limits<uint64_t>::max ());
	uint64_t offset_optional_impl (uint64_t = 0);
	bool rpc_control_impl ();
};
}