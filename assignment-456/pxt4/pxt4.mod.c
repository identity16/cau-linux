#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x7459220b, "module_layout" },
	{ 0x47a0cdcb, "mb_cache_entry_find_next" },
	{ 0xe7750f8, "kobject_put" },
	{ 0x95dc3deb, "blkdev_issue_discard" },
	{ 0x31d7ffc5, "jbd3_inode_cache" },
	{ 0xeba97120, "d_path" },
	{ 0x1fd1d2a5, "kmem_cache_destroy" },
	{ 0x334b33a, "fs_bio_set" },
	{ 0xd445cb97, "page_zero_new_buffers" },
	{ 0xccab4ef7, "dquot_alloc" },
	{ 0xbe54c689, "iget_failed" },
	{ 0x44a8df9e, "dquot_destroy" },
	{ 0xca5673b0, "__blkdev_issue_discard" },
	{ 0xedec5990, "kmalloc_caches" },
	{ 0x40560960, "fscrypt_has_permitted_context" },
	{ 0x3fe2ccbe, "memweight" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x6c48e3e4, "fscrypt_inherit_context" },
	{ 0xeab06e3d, "fscrypt_free_inode" },
	{ 0xe369b5d8, "iomap_seek_data" },
	{ 0x3a966e1c, "drop_nlink" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xe569f4be, "__bdevname" },
	{ 0x15844e58, "sb_min_blocksize" },
	{ 0xc9661a27, "submit_bio_wait" },
	{ 0xbdcbb617, "bio_devname" },
	{ 0x1ed8b599, "__x86_indirect_thunk_r8" },
	{ 0x9914550d, "mark_buffer_dirty_inode" },
	{ 0x53b954a2, "up_read" },
	{ 0xdaddbd5a, "trace_handle_return" },
	{ 0x7410aba2, "strreplace" },
	{ 0x84502a47, "blk_status_to_errno" },
	{ 0x76c4c529, "bio_alloc_bioset" },
	{ 0xf1007a76, "make_bad_inode" },
	{ 0x56b51bbf, "dquot_get_next_dqblk" },
	{ 0xdcda97fb, "__put_devmap_managed_page" },
	{ 0x9a1e4cc5, "__mark_inode_dirty" },
	{ 0x57a54ba5, "d_invalidate" },
	{ 0x98dcc8b9, "dquot_writeback_dquots" },
	{ 0x6877fb64, "__set_page_dirty_nobuffers" },
	{ 0x59a11eaf, "crypto_alloc_shash" },
	{ 0x97ca01a1, "filemap_fault" },
	{ 0x349cba85, "strchr" },
	{ 0xf84b26b2, "dquot_quotactl_sysfile_ops" },
	{ 0xfee7274f, "dqput" },
	{ 0x48fd7b93, "fscrypt_get_symlink" },
	{ 0xb48c5f09, "fscrypt_encrypt_pagecache_blocks" },
	{ 0xc46bedbf, "proc_create_seq_private" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xf995ffcc, "__cleancache_get_page" },
	{ 0xb2686996, "dqget" },
	{ 0xad72306e, "generic_write_checks" },
	{ 0xbe02e46a, "fsverity_ioctl_measure" },
	{ 0xac537ac2, "percpu_counter_destroy" },
	{ 0x73350706, "__page_symlink" },
	{ 0xa0fbac79, "wake_up_bit" },
	{ 0x754d539c, "strlen" },
	{ 0xcc2cc74c, "fsverity_cleanup_inode" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x65c1e935, "generic_file_llseek_size" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x69f28367, "dquot_acquire" },
	{ 0x8f21dc3, "filemap_write_and_wait_range" },
	{ 0x52ed1880, "jbd3_journal_forget" },
	{ 0xe646d717, "jbd3_journal_stop" },
	{ 0x3a795b71, "__generic_file_write_iter" },
	{ 0xe014751, "jbd3_journal_force_commit" },
	{ 0xd53c42ca, "__generic_file_fsync" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0xadfd6f08, "proc_create_single_data" },
	{ 0xcb48ab33, "from_kuid_munged" },
	{ 0xcfb8a37, "dget_parent" },
	{ 0x64999478, "congestion_wait" },
	{ 0xb1cfd4a9, "end_buffer_write_sync" },
	{ 0x287acd9f, "bdev_read_only" },
	{ 0x64925270, "__dax_synchronous" },
	{ 0xf1682866, "block_invalidatepage" },
	{ 0x263ed23b, "__x86_indirect_thunk_r12" },
	{ 0x19f462ab, "kfree_call_rcu" },
	{ 0x39e28e12, "generic_fh_to_parent" },
	{ 0x163141cf, "seq_escape" },
	{ 0x7cfbb59a, "iomap_zero_range" },
	{ 0x6e6bb587, "dquot_file_open" },
	{ 0x211dba95, "dquot_get_next_id" },
	{ 0x856076f4, "block_is_partially_uptodate" },
	{ 0x7242d92, "put_dax" },
	{ 0x42a5b6bd, "dquot_mark_dquot_dirty" },
	{ 0x3f84a701, "jbd3_journal_dirty_metadata" },
	{ 0x4e68e9be, "rb_next_postorder" },
	{ 0xe337dcfb, "jbd3_journal_check_available_features" },
	{ 0x9cb39373, "seq_puts" },
	{ 0x98e3bbde, "is_bad_inode" },
	{ 0xae31b3e7, "blkdev_issue_flush" },
	{ 0x5dee76cd, "pagecache_get_page" },
	{ 0x66ae3bfd, "dquot_quota_on_mount" },
	{ 0xc95c473e, "jbd3_journal_force_commit_nested" },
	{ 0x25820c64, "fs_overflowuid" },
	{ 0xacf4d843, "match_strdup" },
	{ 0xcb7a2599, "posix_acl_update_mode" },
	{ 0x7ab88a45, "system_freezing_cnt" },
	{ 0xac8597d5, "mb_cache_entry_get" },
	{ 0x32ae5741, "_raw_read_lock" },
	{ 0x2b20a022, "__lock_page" },
	{ 0x891536ee, "ll_rw_block" },
	{ 0xd509f6a3, "tag_pages_for_writeback" },
	{ 0xf6118478, "filemap_write_and_wait" },
	{ 0x884f7711, "__lock_buffer" },
	{ 0xea45ba20, "__percpu_down_read" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x87bc50e4, "touch_atime" },
	{ 0xc0a3d105, "find_next_bit" },
	{ 0xdf566a59, "__x86_indirect_thunk_r9" },
	{ 0x41b0b9cc, "dput" },
	{ 0x18574a1, "mb_cache_entry_delete" },
	{ 0xc4142837, "seq_printf" },
	{ 0x56470118, "__warn_printk" },
	{ 0xa3f40039, "dquot_quota_off" },
	{ 0xaf5944ba, "fscrypt_ioctl_get_policy" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xb4c99b4e, "remove_proc_entry" },
	{ 0xf9fb78e3, "jbd3_journal_init_jbd_inode" },
	{ 0xee91879b, "rb_first_postorder" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x4829cf6b, "fscrypt_enqueue_decrypt_work" },
	{ 0x9034a696, "mempool_destroy" },
	{ 0x44e9a829, "match_token" },
	{ 0x92e8e9ab, "fsverity_enqueue_verify_work" },
	{ 0xc29957c3, "__x86_indirect_thunk_rcx" },
	{ 0x80280f8, "buffer_migrate_page" },
	{ 0x55b81fae, "inc_nlink" },
	{ 0x1d09f62f, "block_read_full_page" },
	{ 0x371ea075, "fscrypt_fname_disk_to_usr" },
	{ 0xcba4abe3, "list_sort" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0xa04b6eb7, "fscrypt_ioctl_add_key" },
	{ 0x5523fd64, "file_path" },
	{ 0x2f322a0c, "init_user_ns" },
	{ 0x53126ecc, "__percpu_counter_sum" },
	{ 0x476b801f, "pagevec_lookup_range" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4a60a0de, "find_inode_nowait" },
	{ 0xe138fb8c, "percpu_counter_add_batch" },
	{ 0x25919974, "add_to_page_cache_lru" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0x4e8b32e0, "mount_bdev" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3d56e7b3, "utf8_unload" },
	{ 0x18ba0ecf, "__dquot_free_space" },
	{ 0x20d63beb, "trace_event_buffer_reserve" },
	{ 0x3eb09dd8, "d_instantiate_new" },
	{ 0x2aad1fd8, "kobject_del" },
	{ 0x6a3cb3a, "generic_read_dir" },
	{ 0xfd902db, "mb_cache_entry_create" },
	{ 0xdee365b0, "_raw_write_trylock" },
	{ 0x4f07f96b, "__getblk_gfp" },
	{ 0xdf2fd6d5, "igrab" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x9c7b8128, "unlock_buffer" },
	{ 0x165b145c, "ex_handler_refcount" },
	{ 0xdda6a320, "noop_direct_IO" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x621094fa, "fsverity_verify_bio" },
	{ 0x40846f97, "__dquot_alloc_space" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x3a0cb9a5, "redirty_page_for_writepage" },
	{ 0xd5304fc6, "fscrypt_free_bounce_page" },
	{ 0x7ebd4be4, "trace_print_flags_seq" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x91076b42, "pagevec_lookup_range_tag" },
	{ 0x6b5f2a8d, "bpf_trace_run3" },
	{ 0xa095e02e, "generic_check_addressable" },
	{ 0xbb3d2c11, "pv_ops" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0xd3b8ea86, "jbd3_journal_destroy" },
	{ 0x8db07afd, "kthread_create_on_node" },
	{ 0xe6749241, "dquot_get_dqblk" },
	{ 0x7268de67, "dax_finish_sync_fault" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x4919c360, "try_to_release_page" },
	{ 0xc267960e, "utf8_validate" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x20b41469, "kobject_create_and_add" },
	{ 0xe40c37ea, "down_write_trylock" },
	{ 0xc5e4a5d1, "cpumask_next" },
	{ 0x3d5e398b, "end_page_writeback" },
	{ 0x5db342c2, "from_kgid_munged" },
	{ 0x866219fb, "wbc_account_cgroup_owner" },
	{ 0xaf0b9916, "fscrypt_drop_inode" },
	{ 0xece784c2, "rb_first" },
	{ 0xb0ad7442, "fscrypt_zeroout_range" },
	{ 0x69a6ffae, "invalidate_bdev" },
	{ 0xb58cd868, "make_kgid" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x2ac0e6e, "PDE_DATA" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x48e76aad, "jbd3_journal_revoke" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0x23ee13fd, "mb_cache_entry_find_first" },
	{ 0x6de13801, "wait_for_completion" },
	{ 0xa0f710cf, "inode_owner_or_capable" },
	{ 0xc5034180, "noop_set_page_dirty" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x57e2053c, "trace_define_field" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x864f9957, "bio_associate_blkg_from_css" },
	{ 0x7e526bfa, "__x86_indirect_thunk_r10" },
	{ 0xc09b4962, "kern_path" },
	{ 0xfb578fc5, "memset" },
	{ 0xfce8f9db, "noop_invalidatepage" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x2210d332, "from_kuid" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0xf47b3d97, "proc_mkdir" },
	{ 0x35c49c6a, "set_task_ioprio" },
	{ 0xed97fa5, "bpf_trace_run1" },
	{ 0x9b420478, "utf8_strncasecmp" },
	{ 0xccc6f7c2, "dax_layout_busy_page" },
	{ 0x5e4fe626, "dquot_alloc_inode" },
	{ 0x3812050a, "_raw_spin_unlock_irqrestore" },
	{ 0xba312d7b, "current_task" },
	{ 0xddd88e3c, "__fscrypt_prepare_symlink" },
	{ 0xe541dad7, "freezing_slow_path" },
	{ 0x6bf919cd, "fscrypt_put_encryption_info" },
	{ 0x2f751416, "from_kprojid" },
	{ 0xf824d270, "__bread_gfp" },
	{ 0x977f511b, "__mutex_init" },
	{ 0xc5850110, "printk" },
	{ 0x596c7181, "jbd3_journal_extend" },
	{ 0x8c3253ec, "_raw_spin_trylock" },
	{ 0x1f1fe509, "kthread_stop" },
	{ 0x63baf9f7, "posix_acl_chmod" },
	{ 0x89bbfc0f, "d_obtain_alias" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x9f73aa71, "dax_writeback_mapping_range" },
	{ 0xbc995328, "iov_iter_alignment" },
	{ 0xe1dcb55f, "__percpu_init_rwsem" },
	{ 0xd25eb83e, "crypto_shash_update" },
	{ 0xf75a745e, "bio_add_page" },
	{ 0x948e389a, "generic_writepages" },
	{ 0xcccf7597, "kobject_init_and_add" },
	{ 0xf1e046cc, "panic" },
	{ 0xd38a1f3e, "__fscrypt_prepare_link" },
	{ 0x76d0746d, "file_remove_privs" },
	{ 0x9976c0d4, "blkdev_issue_zeroout" },
	{ 0x4e3492de, "jbd3_complete_transaction" },
	{ 0x479c3c86, "find_next_zero_bit" },
	{ 0x205cdca4, "jbd3_journal_load" },
	{ 0xd56c200d, "__fscrypt_encrypt_symlink" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x4e91f1a2, "fscrypt_ioctl_remove_key" },
	{ 0xceec8abd, "__mb_cache_entry_free" },
	{ 0x9166fada, "strncpy" },
	{ 0x9ed83b29, "trace_event_reg" },
	{ 0xd5263820, "mb_cache_destroy" },
	{ 0x77057b57, "__sync_dirty_buffer" },
	{ 0xd4432990, "from_kgid" },
	{ 0xc652a170, "jbd3_trans_will_send_data_barrier" },
	{ 0xbd6841d4, "crc16" },
	{ 0x16ab2196, "fscrypt_decrypt_bio" },
	{ 0x1544f4ba, "dquot_enable" },
	{ 0x6168380e, "seq_putc" },
	{ 0xf15d0578, "security_inode_init_security" },
	{ 0x5a921311, "strncmp" },
	{ 0xbee380ba, "posix_acl_alloc" },
	{ 0x5792f848, "strlcpy" },
	{ 0x593c1bac, "__x86_indirect_thunk_rbx" },
	{ 0xa07c2c57, "kmem_cache_free" },
	{ 0x9dc84671, "set_nlink" },
	{ 0xd416b24d, "fscrypt_ioctl_set_policy" },
	{ 0x2ab7989d, "mutex_lock" },
	{ 0x2588cddc, "__wait_on_buffer" },
	{ 0x1c55d392, "file_update_time" },
	{ 0x5a245f6d, "_raw_write_lock" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xeff83121, "setattr_copy" },
	{ 0x5ae28674, "bpf_trace_run5" },
	{ 0x1d8b9535, "dquot_resume" },
	{ 0xcf1c1b8d, "__fscrypt_prepare_rename" },
	{ 0x59b7a504, "wait_on_page_writeback" },
	{ 0xa681fe88, "generate_random_uuid" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xca503cea, "thaw_bdev" },
	{ 0xf67124c1, "unlock_two_nondirectories" },
	{ 0x2f16cdfd, "jbd3_journal_clear_features" },
	{ 0x277083e8, "insert_inode_locked" },
	{ 0xeee90dc9, "init_uts_ns" },
	{ 0xb7d7c500, "sync_dirty_buffer" },
	{ 0xfda9581f, "prandom_u32" },
	{ 0x4ae72e08, "truncate_pagecache" },
	{ 0x5240ee7, "percpu_counter_batch" },
	{ 0x5fa3630e, "kmem_cache_create_usercopy" },
	{ 0xe151b6ee, "blkdev_get_by_dev" },
	{ 0x7ad0f76a, "set_cached_acl" },
	{ 0xafa4e654, "vfs_ioc_setflags_prepare" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0x1a3b89a6, "thp_get_unmapped_area" },
	{ 0x4e3567f7, "match_int" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x8ef38868, "unlock_page" },
	{ 0x504f092a, "generic_file_read_iter" },
	{ 0xe3a53f4c, "sort" },
	{ 0xce807a25, "up_write" },
	{ 0x6fe7434, "jbd3_journal_restart" },
	{ 0x57bc19d2, "down_write" },
	{ 0xa0fd0123, "fput" },
	{ 0xce24f1a4, "perf_trace_run_bpf_submit" },
	{ 0x8c8aad1e, "jbd3_journal_release_jbd_inode" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0xd82a2711, "inode_nohighmem" },
	{ 0x42160169, "flush_workqueue" },
	{ 0xdd640079, "posix_acl_create" },
	{ 0x1574c3c6, "__brelse" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xcd6c5d9a, "percpu_up_write" },
	{ 0x739758b1, "bio_put" },
	{ 0x9f1bcca5, "jbd3_journal_get_write_access" },
	{ 0x7e7b0c19, "dquot_set_dqblk" },
	{ 0x24e4f228, "__task_pid_nr_ns" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0x48f5cd08, "dquot_claim_space_nodirty" },
	{ 0xdab3e267, "jbd3_journal_lock_updates" },
	{ 0xb301748d, "file_write_and_wait_range" },
	{ 0xd6d2a096, "inode_init_once" },
	{ 0x33f96a16, "fsverity_verify_page" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x84588d42, "bh_submit_read" },
	{ 0xf8711aa0, "jbd3_journal_clear_err" },
	{ 0x32e2ef6e, "jbd3_journal_init_dev" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x5e332b52, "__var_waitqueue" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0xe4fb2be3, "mnt_drop_write_file" },
	{ 0x479f68ad, "submit_bio" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf2215f74, "blk_finish_plug" },
	{ 0x80fa8f12, "block_commit_write" },
	{ 0xb442b938, "jbd3_journal_begin_ordered_truncate" },
	{ 0xd2ee4970, "invalidate_inode_buffers" },
	{ 0x5d49aabc, "init_wait_var_entry" },
	{ 0xa055dafb, "jbd3_journal_flush" },
	{ 0x4a741a28, "dquot_reclaim_space_nodirty" },
	{ 0x861d3e50, "kmem_cache_alloc" },
	{ 0x8f568188, "dquot_initialize_needed" },
	{ 0xb2883355, "jbd3_journal_invalidatepage" },
	{ 0x1bd3c261, "blkdev_put" },
	{ 0x65433c2f, "unregister_shrinker" },
	{ 0x9f62808b, "dquot_quota_on" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x799185de, "fsverity_file_open" },
	{ 0x5900cafe, "jbd3_journal_init_inode" },
	{ 0xac50e529, "dquot_initialize" },
	{ 0x5195b8ee, "fscrypt_file_open" },
	{ 0x3b7d8084, "sync_mapping_buffers" },
	{ 0xb05ba321, "generic_block_fiemap" },
	{ 0xa916b694, "strnlen" },
	{ 0x51a4d68e, "__filemap_set_wb_err" },
	{ 0x839dcb2b, "pagecache_write_end" },
	{ 0x8bcbc0e0, "wait_for_stable_page" },
	{ 0xd64b0a8e, "fs_kobj" },
	{ 0x4ba20fb3, "bdevname" },
	{ 0x3989a913, "sync_blockdev" },
	{ 0xb628d51, "block_write_end" },
	{ 0xa3e59772, "truncate_inode_pages_final" },
	{ 0x8241f82, "create_empty_buffers" },
	{ 0x6fc9ef9a, "make_kuid" },
	{ 0x2648dc07, "try_to_free_buffers" },
	{ 0x3b9f1087, "trace_event_ignore_this_pid" },
	{ 0xf82ec573, "rb_prev" },
	{ 0x2910e6d8, "jbd3__journal_start" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x3cb4a349, "fscrypt_fname_alloc_buffer" },
	{ 0x1000e51, "schedule" },
	{ 0x3f48d7f7, "jbd3_journal_errno" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x1f31d5a, "iomap_seek_hole" },
	{ 0x5e6d920c, "make_kprojid" },
	{ 0xd1bdb31b, "generic_write_end" },
	{ 0x8f43ad84, "dquot_quota_sync" },
	{ 0xcae42709, "jbd3_journal_update_sb_errno" },
	{ 0xce19729, "mb_cache_entry_touch" },
	{ 0x605790dc, "fiemap_fill_next_extent" },
	{ 0x1953c958, "mempool_create" },
	{ 0x499cb97, "unlock_new_inode" },
	{ 0x84710cf0, "mnt_want_write_file" },
	{ 0x8b8059bd, "in_group_p" },
	{ 0xa0fcaaeb, "kill_block_super" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x90cc322f, "lock_two_nondirectories" },
	{ 0x53bd49a, "inode_newsize_ok" },
	{ 0xa263892b, "fscrypt_fname_free_buffer" },
	{ 0x536b294f, "jbd3_journal_inode_ranged_write" },
	{ 0x97b9fa18, "page_cache_sync_readahead" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0xbfdcb43a, "__x86_indirect_thunk_r11" },
	{ 0x4482cdb, "__refrigerator" },
	{ 0x8f673234, "crypto_destroy_tfm" },
	{ 0xcc6f4548, "jbd3_journal_abort" },
	{ 0x8542ab79, "fscrypt_setup_filename" },
	{ 0xddc69e4d, "trace_event_buffer_commit" },
	{ 0xc0af0f07, "wake_up_process" },
	{ 0xe0955f76, "utf8_casefold" },
	{ 0xb2341be4, "fscrypt_decrypt_pagecache_blocks" },
	{ 0x20cbb30a, "__percpu_counter_init" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfdc3d3fc, "simple_get_link" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0x67d32512, "vfs_setpos" },
	{ 0x7d1ff3c7, "clear_page_dirty_for_io" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xe7a8f47a, "submit_bh" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0x84aa78ec, "path_put" },
	{ 0x9a3e4bed, "kmem_cache_alloc_trace" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0xdbf17652, "_raw_spin_lock" },
	{ 0x8fb8009, "dquot_drop" },
	{ 0x89b5d0d0, "fscrypt_ioctl_get_policy_ex" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x51760917, "_raw_spin_lock_irqsave" },
	{ 0x81ebb951, "fsverity_prepare_setattr" },
	{ 0xcbe0fe99, "sync_inode_metadata" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xf12f47be, "kmem_cache_create" },
	{ 0xb8f31145, "d_tmpfile" },
	{ 0x643db0c9, "dquot_transfer" },
	{ 0x8b4894bf, "register_filesystem" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x14f5884b, "jbd3_journal_inode_ranged_wait" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x8d076002, "event_triggers_call" },
	{ 0x5d8c3676, "vfs_ioc_fssetxattr_check" },
	{ 0xf1e089d0, "dax_iomap_fault" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x8db3b2c4, "__pagevec_release" },
	{ 0x2581e3be, "remove_proc_subtree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xe2f25e9a, "jbd3_log_wait_commit" },
	{ 0x5c666b51, "bpf_trace_run2" },
	{ 0x6b2d2bf1, "__test_set_page_writeback" },
	{ 0xeca4e8f2, "I_BDEV" },
	{ 0x22b21375, "iter_file_splice_write" },
	{ 0x79400224, "blockdev_superblock" },
	{ 0xb4c72c15, "freeze_bdev" },
	{ 0x6b209b49, "jbd3_journal_wipe" },
	{ 0x7ede2eec, "iput" },
	{ 0x15d8e522, "dax_iomap_rw" },
	{ 0x7812c047, "__vmalloc" },
	{ 0x8f186b5f, "jbd3_journal_try_to_free_buffers" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x250f2a02, "read_cache_page" },
	{ 0x37a0cba, "kfree" },
	{ 0x38ed444d, "truncate_pagecache_range" },
	{ 0x3dc9d8c1, "inode_dio_wait" },
	{ 0xda51701e, "page_get_link" },
	{ 0x966b58bf, "d_find_any_alias" },
	{ 0x214809fb, "__percpu_up_read" },
	{ 0x71c86502, "ihold" },
	{ 0x69acdf38, "memcpy" },
	{ 0x2a09a330, "__sb_end_write" },
	{ 0xd634a71d, "trace_event_raw_init" },
	{ 0x638c7869, "current_time" },
	{ 0x7208cb45, "jbd3_journal_set_features" },
	{ 0xaa369563, "generic_error_remove_page" },
	{ 0x4690d310, "d_splice_alias" },
	{ 0xb71589f0, "skip_spaces" },
	{ 0x28fa224a, "register_shrinker" },
	{ 0x96c11d79, "__breadahead_gfp" },
	{ 0xfc399557, "utf8_load" },
	{ 0xc550e94e, "end_buffer_read_sync" },
	{ 0x45376e68, "block_page_mkwrite" },
	{ 0xa88b441f, "sync_filesystem" },
	{ 0xb158dd0d, "__set_page_dirty_buffers" },
	{ 0x4a0609d9, "sb_set_blocksize" },
	{ 0x743ba47e, "__sb_start_write" },
	{ 0x15af7f4, "system_state" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xf848708d, "__bforget" },
	{ 0xd58ad70d, "d_make_root" },
	{ 0xe5203404, "fscrypt_ioctl_get_key_status" },
	{ 0xe3a155c2, "__blockdev_direct_IO" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcdf4a2ef, "inode_set_flags" },
	{ 0xfd01a250, "inode_needs_sync" },
	{ 0xa428078a, "__block_write_begin" },
	{ 0x16325294, "__find_get_block" },
	{ 0x289daa88, "jbd3_journal_free_reserved" },
	{ 0xca9360b5, "rb_next" },
	{ 0x9896f0bf, "mark_buffer_dirty" },
	{ 0x4895d523, "__fscrypt_prepare_lookup" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0x13583a03, "bpf_trace_run6" },
	{ 0xc8ecc45, "fs_dax_get_by_bdev" },
	{ 0xbbfbcb0d, "unregister_filesystem" },
	{ 0xca8f6c91, "init_special_inode" },
	{ 0x84c0265, "dquot_get_state" },
	{ 0x73fa4280, "jbd3_journal_start_commit" },
	{ 0x6b6cdcd5, "trace_raw_output_prep" },
	{ 0x8ac7e0d0, "try_to_writeback_inodes_sb" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x26edb775, "jbd3_journal_start_reserved" },
	{ 0x8897195d, "filemap_map_pages" },
	{ 0x29361773, "complete" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x5e78d1ad, "fiemap_check_flags" },
	{ 0x2947182d, "new_inode" },
	{ 0x8888b156, "trace_seq_printf" },
	{ 0xb0e602eb, "memmove" },
	{ 0xa7d2d66e, "generic_file_splice_read" },
	{ 0x59686d62, "fscrypt_ioctl_remove_key_all_users" },
	{ 0xbe22d1d3, "__bdev_dax_supported" },
	{ 0x161b3ca4, "set_blocksize" },
	{ 0x4c38d4e0, "utf8_strncasecmp_folded" },
	{ 0xb6812eb9, "dquot_free_inode" },
	{ 0x2945bad7, "dquot_release" },
	{ 0xd3a36df9, "dquot_disable" },
	{ 0x9984f62b, "generic_fh_to_dentry" },
	{ 0x31867396, "grab_cache_page_write_begin" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4cdb4ece, "percpu_down_write" },
	{ 0xa87e6d81, "dquot_commit_info" },
	{ 0xffb44ec1, "dquot_set_dqinfo" },
	{ 0x601ce8cf, "__cleancache_init_fs" },
	{ 0xbf0392b8, "page_mapped" },
	{ 0x384841e0, "bpf_trace_run4" },
	{ 0xd172461b, "clear_inode" },
	{ 0xdd2c169b, "mb_cache_create" },
	{ 0x7a9b37e8, "blk_start_plug" },
	{ 0xdf9208c0, "alloc_workqueue" },
	{ 0x811a40a7, "jbd3_journal_unlock_updates" },
	{ 0x622bfb1f, "pagecache_isize_extended" },
	{ 0x87c2517f, "fsverity_ioctl_enable" },
	{ 0x19973b71, "d_instantiate" },
	{ 0x2b525b94, "pagecache_write_begin" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xab3192f1, "__dquot_transfer" },
	{ 0xafbc0dbd, "jbd3_journal_get_create_access" },
	{ 0x3fa55769, "__put_page" },
	{ 0x7cc76fa9, "filemap_flush" },
	{ 0x5c643c8a, "generic_block_bmap" },
	{ 0xa1a59153, "file_check_and_advance_wb_err" },
	{ 0xf41f7e33, "clear_nlink" },
	{ 0xc329e0c2, "fscrypt_get_encryption_info" },
	{ 0xc87adb4d, "iget_locked" },
	{ 0xf75c191, "vfs_fsync_range" },
	{ 0x5d92c2e, "setattr_prepare" },
	{ 0x8de6e8c0, "generic_fillattr" },
	{ 0xf49f62ac, "jbd3_journal_blocks_per_page" },
	{ 0x591d449d, "jbd3_transaction_committed" },
	{ 0xdbfc0b21, "inode_init_owner" },
	{ 0x4f53d497, "noop_backing_dev_info" },
	{ 0x84294343, "bh_uptodate_or_lock" },
	{ 0x8a59702, "percpu_free_rwsem" },
	{ 0x23ae1e03, "truncate_inode_pages" },
	{ 0xfbb43137, "dquot_commit" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x68609863, "bio_associate_blkg" },
	{ 0xdf929370, "fs_overflowgid" },
	{ 0x8a35b432, "sme_me_mask" },
};

MODULE_INFO(depends, "jbd3");


MODULE_INFO(srcversion, "4422E75197D9F392F1160AB");
