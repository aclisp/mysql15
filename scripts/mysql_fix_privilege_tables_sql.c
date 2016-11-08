const char* mysql_fix_privilege_tables={
"-- Copyright (c) 2007, 2008 MySQL AB, 2009 Sun Microsystems, Inc.\n "
"-- Use is subject to license terms.\n "
"-- \n "
"-- This program is free software; you can redistribute it and/or modify\n "
"-- it under the terms of the GNU General Public License as published by\n "
"-- the Free Software Foundation; version 2 of the License.\n "
"-- \n "
"-- This program is distributed in the hope that it will be useful,\n "
"-- but WITHOUT ANY WARRANTY; without even the implied warranty of\n "
"-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n "
"-- GNU General Public License for more details.\n "
"-- \n "
"-- You should have received a copy of the GNU General Public License\n "
"-- along with this program; if not, write to the Free Software\n "
"-- Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA\n "
"\n "
"--\n "
"-- The system tables of MySQL Server\n "
"--\n "
"\n "
"set sql_mode='';\n "
"set storage_engine=myisam;\n "
"\n "
"CREATE TABLE IF NOT EXISTS db (   Host char(60) binary DEFAULT '' NOT NULL, Db char(64) binary DEFAULT '' NOT NULL, User char(16) binary DEFAULT '' NOT NULL, Select_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Insert_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Update_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Delete_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT"
" NULL, Drop_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Grant_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, References_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Index_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Alter_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT "
"'N' NOT NULL, Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, PRIMARY KEY Host (Host,Db,User), KEY User (User) ) engine=MyISAM CHARACTER SET utf8 COLLATE utf8_bin comment='Dat"
"abase privileges';\n "
"\n "
"-- Remember for later if db table already existed\n "
"set @had_db_table= @@warning_count != 0;\n "
"\n "
"CREATE TABLE IF NOT EXISTS host (  Host char(60) binary DEFAULT '' NOT NULL, Db char(64) binary DEFAULT '' NOT NULL, Select_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Insert_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Update_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Delete_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Drop_priv enum('N','Y') COLLATE ut"
"f8_general_ci DEFAULT 'N' NOT NULL, Grant_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, References_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Index_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Alter_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_view_priv enum('N','"
"Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, PRIMARY KEY Host (Host,Db) ) engine=MyISAM CHARACTER SET utf8 COLLATE utf8_bin comment='Host privileges;  Merged with database privileges';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS user (   Host char(60) binary DEFAULT '' NOT NULL, User char(16) binary DEFAULT '' NOT NULL, Password char(41) character set latin1 collate latin1_bin DEFAULT '' NOT NULL, Select_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Insert_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Update_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Delete_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_priv enum('N','Y'"
") COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Drop_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Reload_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Shutdown_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Process_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, File_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Grant_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, References_priv enum('N','Y') COL"
"LATE utf8_general_ci DEFAULT 'N' NOT NULL, Index_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Alter_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Show_db_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Super_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Execute_priv enum('N','"
"Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Repl_slave_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Repl_client_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NUL"
"L, Create_user_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, ssl_type enum('','ANY','X509', 'SPECIFIED') COLLATE utf8_general_ci DEFAULT '' NOT NULL, ssl_cipher BLOB NOT NULL, x509_issuer BLOB NOT NULL, x509_subject BLOB NOT NULL, max_questions int(11) unsigned DEFAULT 0  NOT NULL, max_updates int(11) unsigned DEFAULT 0  NOT NULL, max_connections int(11) unsigned DEFAULT 0  NOT NULL, max_user_connections int(11) unsigned DEFAULT 0  NOT NULL, PRIMARY KEY Host (Host,User) ) engine=MyISAM C"
"HARACTER SET utf8 COLLATE utf8_bin comment='Users and global privileges';\n "
"\n "
"-- Remember for later if user table already existed\n "
"set @had_user_table= @@warning_count != 0;\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS func (  name char(64) binary DEFAULT '' NOT NULL, ret tinyint(1) DEFAULT '0' NOT NULL, dl char(128) DEFAULT '' NOT NULL, type enum ('function','aggregate') COLLATE utf8_general_ci NOT NULL, PRIMARY KEY (name) ) engine=MyISAM CHARACTER SET utf8 COLLATE utf8_bin   comment='User defined functions';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS tables_priv ( Host char(60) binary DEFAULT '' NOT NULL, Db char(64) binary DEFAULT '' NOT NULL, User char(16) binary DEFAULT '' NOT NULL, Table_name char(64) binary DEFAULT '' NOT NULL, Grantor char(77) DEFAULT '' NOT NULL, Timestamp timestamp(14), Table_priv set('Select','Insert','Update','Delete','Create','Drop','Grant','References','Index','Alter','Create View','Show view') COLLATE utf8_general_ci DEFAULT '' NOT NULL, Column_priv set('Select','Insert','Update','References') CO"
"LLATE utf8_general_ci DEFAULT '' NOT NULL, PRIMARY KEY (Host,Db,User,Table_name), KEY Grantor (Grantor) ) engine=MyISAM CHARACTER SET utf8 COLLATE utf8_bin   comment='Table privileges';\n "
"\n "
"CREATE TABLE IF NOT EXISTS columns_priv ( Host char(60) binary DEFAULT '' NOT NULL, Db char(64) binary DEFAULT '' NOT NULL, User char(16) binary DEFAULT '' NOT NULL, Table_name char(64) binary DEFAULT '' NOT NULL, Column_name char(64) binary DEFAULT '' NOT NULL, Timestamp timestamp(14), Column_priv set('Select','Insert','Update','References') COLLATE utf8_general_ci DEFAULT '' NOT NULL, PRIMARY KEY (Host,Db,User,Table_name,Column_name) ) engine=MyISAM CHARACTER SET utf8 COLLATE utf8_bin   comment='Column p"
"rivileges';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS help_topic ( help_topic_id int unsigned not null, name char(64) not null, help_category_id smallint unsigned not null, description text not null, example  text not null, url char(128) not null, primary key (help_topic_id), unique index (name) ) engine=MyISAM CHARACTER SET utf8   comment='help topics';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS help_category ( help_category_id smallint unsigned not null, name  char(64) not null, parent_category_id smallint unsigned null, url char(128) not null, primary key (help_category_id), unique index (name) ) engine=MyISAM CHARACTER SET utf8   comment='help categories';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS help_relation ( help_topic_id int unsigned not null references help_topic, help_keyword_id  int unsigned not null references help_keyword, primary key (help_keyword_id, help_topic_id) ) engine=MyISAM CHARACTER SET utf8 comment='keyword-topic relation';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS help_keyword (   help_keyword_id  int unsigned not null, name char(64) not null, primary key (help_keyword_id), unique index (name) ) engine=MyISAM CHARACTER SET utf8 comment='help keywords';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS time_zone_name (   Name char(64) NOT NULL, Time_zone_id int unsigned NOT NULL, PRIMARY KEY Name (Name) ) engine=MyISAM CHARACTER SET utf8   comment='Time zone names';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS time_zone (   Time_zone_id int unsigned NOT NULL auto_increment, Use_leap_seconds enum('Y','N') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL, PRIMARY KEY TzId (Time_zone_id) ) engine=MyISAM CHARACTER SET utf8   comment='Time zones';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS time_zone_transition (   Time_zone_id int unsigned NOT NULL, Transition_time bigint signed NOT NULL, Transition_type_id int unsigned NOT NULL, PRIMARY KEY TzIdTranTime (Time_zone_id, Transition_time) ) engine=MyISAM CHARACTER SET utf8   comment='Time zone transitions';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS time_zone_transition_type (   Time_zone_id int unsigned NOT NULL, Transition_type_id int unsigned NOT NULL, Offset int signed DEFAULT 0 NOT NULL, Is_DST tinyint unsigned DEFAULT 0 NOT NULL, Abbreviation char(8) DEFAULT '' NOT NULL, PRIMARY KEY TzIdTrTId (Time_zone_id, Transition_type_id) ) engine=MyISAM CHARACTER SET utf8   comment='Time zone transition types';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS time_zone_leap_second (   Transition_time bigint signed NOT NULL, Correction int signed NOT NULL, PRIMARY KEY TranTime (Transition_time) ) engine=MyISAM CHARACTER SET utf8   comment='Leap seconds information for time zones';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS proc ( db char(64) collate utf8_bin DEFAULT '' NOT NULL, name  char(64) DEFAULT '' NOT NULL, type  enum('FUNCTION','PROCEDURE') NOT NULL, specific_name char(64) DEFAULT '' NOT NULL, language  enum('SQL') DEFAULT 'SQL' NOT NULL, sql_data_access enum('CONTAINS_SQL', 'NO_SQL', 'READS_SQL_DATA', 'MODIFIES_SQL_DATA' ) DEFAULT 'CONTAINS_SQL' NOT NULL, is_deterministic  enum('YES','NO') DEFAULT 'NO' NOT NULL, security_type enum('INVOKER','DEFINER') DEFAULT 'DEFINER' NOT NULL, param_list"
"  blob NOT NULL, returns char(64) DEFAULT '' NOT NULL, body  longblob NOT NULL, definer char(77) collate utf8_bin DEFAULT '' NOT NULL, created timestamp, modified timestamp, sql_mode set( 'REAL_AS_FLOAT', 'PIPES_AS_CONCAT', 'ANSI_QUOTES', 'IGNORE_SPACE', 'NOT_USED', 'ONLY_FULL_GROUP_BY', 'NO_UNSIGNED_SUBTRACTION', 'NO_DIR_IN_CREATE', 'POSTGRESQL', 'ORACLE', 'MSSQL', 'DB2', 'MAXDB', 'NO_KEY_OPTIONS', 'NO_TABLE_OPTIONS', 'NO_FIELD_OPTIONS', 'MYSQL323', 'MYSQL40', 'ANSI', 'NO_AUTO_VALUE_ON_ZERO', 'NO_BACKSLAS"
"H_ESCAPES', 'STRICT_TRANS_TABLES', 'STRICT_ALL_TABLES', 'NO_ZERO_IN_DATE', 'NO_ZERO_DATE', 'INVALID_DATES', 'ERROR_FOR_DIVISION_BY_ZERO', 'TRADITIONAL', 'NO_AUTO_CREATE_USER', 'HIGH_NOT_PRECEDENCE' ) DEFAULT '' NOT NULL, comment char(64) collate utf8_bin DEFAULT '' NOT NULL, PRIMARY KEY (db,name,type) ) engine=MyISAM character set utf8 comment='Stored Procedures';\n "
"\n "
"\n "
"CREATE TABLE IF NOT EXISTS procs_priv ( Host char(60) binary DEFAULT '' NOT NULL, Db char(64) binary DEFAULT '' NOT NULL, User char(16) binary DEFAULT '' NOT NULL, Routine_name char(64) COLLATE utf8_general_ci DEFAULT '' NOT NULL, Routine_type enum('FUNCTION','PROCEDURE') NOT NULL, Grantor char(77) DEFAULT '' NOT NULL, Proc_priv set('Execute','Alter Routine','Grant') COLLATE utf8_general_ci DEFAULT '' NOT NULL, Timestamp timestamp(14), PRIMARY KEY (Host,Db,User,Routine_name,Routine_type), KEY Grantor (Gran"
"tor) ) engine=MyISAM CHARACTER SET utf8 COLLATE utf8_bin   comment='Procedure privileges';\n "
"\n "
"# Copyright (c) 2003, 2007 MySQL AB, 2009 Sun Microsystems, Inc.\n "
"# Use is subject to license terms.\n "
"# \n "
"# This program is free software; you can redistribute it and/or modify\n "
"# it under the terms of the GNU General Public License as published by\n "
"# the Free Software Foundation; version 2 of the License.\n "
"# \n "
"# This program is distributed in the hope that it will be useful,\n "
"# but WITHOUT ANY WARRANTY; without even the implied warranty of\n "
"# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n "
"# GNU General Public License for more details.\n "
"# \n "
"# You should have received a copy of the GNU General Public License\n "
"# along with this program; if not, write to the Free Software\n "
"# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA\n "
"\n "
"# This part converts any old privilege tables to privilege tables suitable\n "
"# for current version of MySQL\n "
"\n "
"# You can safely ignore all 'Duplicate column' and 'Unknown column' errors\n "
"# because these just mean that your tables are already up to date.\n "
"# This script is safe to run even if your tables are already up to date!\n "
"\n "
"# On unix, you should use the mysql_fix_privilege_tables script to execute\n "
"# this sql script.\n "
"# On windows you should do 'mysql --force mysql < mysql_fix_privilege_tables.sql'\n "
"\n "
"set sql_mode='';\n "
"set storage_engine=MyISAM;\n "
"\n "
"ALTER TABLE user add File_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL;\n "
"\n "
"# Detect whether or not we had the Grant_priv column\n "
"SET @hadGrantPriv:=0;\n "
"SELECT @hadGrantPriv:=1 FROM user WHERE Grant_priv LIKE '%';\n "
"\n "
"ALTER TABLE user add Grant_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add References_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add Index_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add Alter_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL;\n "
"ALTER TABLE host add Grant_priv enum('N','Y') NOT NULL,add References_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add Index_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add Alter_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL;\n "
"ALTER TABLE db add Grant_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add References_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add Index_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL,add Alter_priv enum('N','Y') COLLATE utf8_general_ci NOT NULL;\n "
"\n "
"# Fix privileges for old tables\n "
"UPDATE user SET Grant_priv=File_priv,References_priv=Create_priv,Index_priv=Create_priv,Alter_priv=Create_priv WHERE @hadGrantPriv = 0;\n "
"UPDATE db SET References_priv=Create_priv,Index_priv=Create_priv,Alter_priv=Create_priv WHERE @hadGrantPriv = 0;\n "
"UPDATE host SET References_priv=Create_priv,Index_priv=Create_priv,Alter_priv=Create_priv WHERE @hadGrantPriv = 0;\n "
"\n "
"#\n "
"# The second alter changes ssl_type to new 4.0.2 format\n "
"# Adding columns needed by GRANT .. REQUIRE (openssl)\n "
"\n "
"ALTER TABLE user\n "
"ADD ssl_type enum('','ANY','X509', 'SPECIFIED') COLLATE utf8_general_ci NOT NULL,\n "
"ADD ssl_cipher BLOB NOT NULL,\n "
"ADD x509_issuer BLOB NOT NULL,\n "
"ADD x509_subject BLOB NOT NULL;\n "
"ALTER TABLE user MODIFY ssl_type enum('','ANY','X509', 'SPECIFIED') NOT NULL;\n "
"\n "
"#\n "
"# tables_priv\n "
"#\n "
"\n "
"ALTER TABLE tables_priv\n "
"  ADD KEY Grantor (Grantor);\n "
"\n "
"ALTER TABLE tables_priv\n "
"  MODIFY Host char(60) NOT NULL default '',\n "
"  MODIFY Db char(64) NOT NULL default '',\n "
"  MODIFY User char(16) NOT NULL default '',\n "
"  MODIFY Table_name char(64) NOT NULL default '',\n "
"  MODIFY Grantor char(77) NOT NULL default '',\n "
"  ENGINE=MyISAM,\n "
"  CONVERT TO CHARACTER SET utf8 COLLATE utf8_bin;\n "
"\n "
"ALTER TABLE tables_priv\n "
"  MODIFY Column_priv set('Select','Insert','Update','References')\n "
"    COLLATE utf8_general_ci DEFAULT '' NOT NULL,\n "
"  MODIFY Table_priv set('Select','Insert','Update','Delete','Create',\n "
"                        'Drop','Grant','References','Index','Alter',\n "
"                        'Create View','Show view')\n "
"    COLLATE utf8_general_ci DEFAULT '' NOT NULL,\n "
"  COMMENT='Table privileges';\n "
"\n "
"#\n "
"# columns_priv\n "
"#\n "
"\n "
"# Name change of Type -> Column_priv from MySQL 3.22.12\n "
"ALTER TABLE columns_priv\n "
"  CHANGE Type Column_priv set('Select','Insert','Update','References')\n "
"    COLLATE utf8_general_ci DEFAULT '' NOT NULL;\n "
"\n "
"ALTER TABLE columns_priv\n "
"  MODIFY Host char(60) NOT NULL default '',\n "
"  MODIFY Db char(64) NOT NULL default '',\n "
"  MODIFY User char(16) NOT NULL default '',\n "
"  MODIFY Table_name char(64) NOT NULL default '',\n "
"  MODIFY Column_name char(64) NOT NULL default '',\n "
"  ENGINE=MyISAM,\n "
"  CONVERT TO CHARACTER SET utf8 COLLATE utf8_bin,\n "
"  COMMENT='Column privileges';\n "
"\n "
"ALTER TABLE columns_priv\n "
"  MODIFY Column_priv set('Select','Insert','Update','References')\n "
"    COLLATE utf8_general_ci DEFAULT '' NOT NULL;\n "
"\n "
"#\n "
"#  Add the new 'type' column to the func table.\n "
"#\n "
"\n "
"ALTER TABLE func add type enum ('function','aggregate') COLLATE utf8_general_ci NOT NULL;\n "
"\n "
"#\n "
"#  Change the user,db and host tables to current format\n "
"#\n "
"\n "
"# Detect whether we had Show_db_priv\n "
"SET @hadShowDbPriv:=0;\n "
"SELECT @hadShowDbPriv:=1 FROM user WHERE Show_db_priv LIKE '%';\n "
"\n "
"ALTER TABLE user\n "
"ADD Show_db_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Alter_priv,\n "
"ADD Super_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Show_db_priv,\n "
"ADD Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Super_priv,\n "
"ADD Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_tmp_table_priv,\n "
"ADD Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Lock_tables_priv,\n "
"ADD Repl_slave_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Execute_priv,\n "
"ADD Repl_client_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Repl_slave_priv;\n "
"\n "
"# Convert privileges so that users have similar privileges as before\n "
"\n "
"UPDATE user SET Show_db_priv= Select_priv, Super_priv=Process_priv, Execute_priv=Process_priv, Create_tmp_table_priv='Y', Lock_tables_priv='Y', Repl_slave_priv=file_priv, Repl_client_priv=File_priv where user<>\"\" AND @hadShowDbPriv = 0;\n "
"\n "
"\n "
"#  Add fields that can be used to limit number of questions and connections\n "
"#  for some users.\n "
"\n "
"ALTER TABLE user\n "
"ADD max_questions int(11) NOT NULL DEFAULT 0 AFTER x509_subject,\n "
"ADD max_updates   int(11) unsigned NOT NULL DEFAULT 0 AFTER max_questions,\n "
"ADD max_connections int(11) unsigned NOT NULL DEFAULT 0 AFTER max_updates;\n "
"\n "
"\n "
"#\n "
"#  Add Create_tmp_table_priv and Lock_tables_priv to db and host\n "
"#\n "
"\n "
"ALTER TABLE db\n "
"ADD Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"ADD Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL;\n "
"ALTER TABLE host\n "
"ADD Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"ADD Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL;\n "
"\n "
"alter table user change max_questions max_questions int(11) unsigned DEFAULT 0  NOT NULL;\n "
"\n "
"\n "
"alter table db comment='Database privileges';\n "
"alter table host comment='Host privileges;  Merged with database privileges';\n "
"alter table user comment='Users and global privileges';\n "
"alter table func comment='User defined functions';\n "
"\n "
"# Convert all tables to UTF-8 with binary collation\n "
"# and reset all char columns to correct width\n "
"ALTER TABLE user\n "
"  MODIFY Host char(60) NOT NULL default '',\n "
"  MODIFY User char(16) NOT NULL default '',\n "
"  ENGINE=MyISAM, CONVERT TO CHARACTER SET utf8 COLLATE utf8_bin;\n "
"ALTER TABLE user\n "
"  MODIFY Password char(41) character set latin1 collate latin1_bin NOT NULL default '',\n "
"  MODIFY Select_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Insert_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Update_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Delete_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Create_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Drop_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Reload_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Shutdown_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Process_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY File_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Grant_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY References_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Index_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Alter_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Show_db_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Super_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Repl_slave_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Repl_client_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY ssl_type enum('','ANY','X509', 'SPECIFIED') COLLATE utf8_general_ci DEFAULT '' NOT NULL;\n "
"\n "
"ALTER TABLE db\n "
"  MODIFY Host char(60) NOT NULL default '',\n "
"  MODIFY Db char(64) NOT NULL default '',\n "
"  MODIFY User char(16) NOT NULL default '',\n "
"  ENGINE=MyISAM, CONVERT TO CHARACTER SET utf8 COLLATE utf8_bin;\n "
"ALTER TABLE db\n "
"  MODIFY  Select_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Insert_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Update_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Delete_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Create_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Drop_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Grant_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  References_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Index_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Alter_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY  Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL;\n "
"\n "
"ALTER TABLE host\n "
"  MODIFY Host char(60) NOT NULL default '',\n "
"  MODIFY Db char(64) NOT NULL default '',\n "
"  ENGINE=MyISAM, CONVERT TO CHARACTER SET utf8 COLLATE utf8_bin;\n "
"ALTER TABLE host\n "
"  MODIFY Select_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Insert_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Update_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Delete_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Create_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Drop_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Grant_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY References_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Index_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Alter_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Create_tmp_table_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL,\n "
"  MODIFY Lock_tables_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL;\n "
"\n "
"ALTER TABLE func\n "
"  ENGINE=MyISAM, CONVERT TO CHARACTER SET utf8 COLLATE utf8_bin;\n "
"ALTER TABLE func\n "
"  MODIFY type enum ('function','aggregate') COLLATE utf8_general_ci NOT NULL;\n "
"\n "
"#\n "
"# Detect whether we had Create_view_priv\n "
"#\n "
"SET @hadCreateViewPriv:=0;\n "
"SELECT @hadCreateViewPriv:=1 FROM user WHERE Create_view_priv LIKE '%';\n "
"\n "
"#\n "
"# Create VIEWs privileges (v5.0)\n "
"#\n "
"ALTER TABLE db ADD Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Lock_tables_priv;\n "
"ALTER TABLE db MODIFY Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Lock_tables_priv;\n "
"\n "
"ALTER TABLE host ADD Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Lock_tables_priv;\n "
"ALTER TABLE host MODIFY Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Lock_tables_priv;\n "
"\n "
"ALTER TABLE user ADD Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Repl_client_priv;\n "
"ALTER TABLE user MODIFY Create_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Repl_client_priv;\n "
"\n "
"#\n "
"# Show VIEWs privileges (v5.0)\n "
"#\n "
"ALTER TABLE db ADD Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_view_priv;\n "
"ALTER TABLE db MODIFY Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_view_priv;\n "
"\n "
"ALTER TABLE host ADD Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_view_priv;\n "
"ALTER TABLE host MODIFY Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_view_priv;\n "
"\n "
"ALTER TABLE user ADD Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_view_priv;\n "
"ALTER TABLE user MODIFY Show_view_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_view_priv;\n "
"\n "
"#\n "
"# Assign create/show view privileges to people who have create provileges\n "
"#\n "
"UPDATE user SET Create_view_priv=Create_priv, Show_view_priv=Create_priv where user<>\"\" AND @hadCreateViewPriv = 0;\n "
"\n "
"#\n "
"#\n "
"#\n "
"SET @hadCreateRoutinePriv:=0;\n "
"SELECT @hadCreateRoutinePriv:=1 FROM user WHERE Create_routine_priv LIKE '%';\n "
"\n "
"#\n "
"# Create PROCEDUREs privileges (v5.0)\n "
"#\n "
"ALTER TABLE db ADD Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Show_view_priv;\n "
"ALTER TABLE db MODIFY Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Show_view_priv;\n "
"\n "
"ALTER TABLE host ADD Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Show_view_priv;\n "
"ALTER TABLE host MODIFY Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Show_view_priv;\n "
"\n "
"ALTER TABLE user ADD Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Show_view_priv;\n "
"ALTER TABLE user MODIFY Create_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Show_view_priv;\n "
"\n "
"#\n "
"# Alter PROCEDUREs privileges (v5.0)\n "
"#\n "
"ALTER TABLE db ADD Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_routine_priv;\n "
"ALTER TABLE db MODIFY Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_routine_priv;\n "
"\n "
"ALTER TABLE host ADD Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_routine_priv;\n "
"ALTER TABLE host MODIFY Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_routine_priv;\n "
"\n "
"ALTER TABLE user ADD Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_routine_priv;\n "
"ALTER TABLE user MODIFY Alter_routine_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Create_routine_priv;\n "
"\n "
"ALTER TABLE db ADD Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Alter_routine_priv;\n "
"ALTER TABLE db MODIFY Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Alter_routine_priv;\n "
"\n "
"ALTER TABLE host ADD Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Alter_routine_priv;\n "
"ALTER TABLE host MODIFY Execute_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Alter_routine_priv;\n "
"\n "
"#\n "
"# Assign create/alter routine privileges to people who have create privileges\n "
"#\n "
"UPDATE user SET Create_routine_priv=Create_priv, Alter_routine_priv=Alter_priv where user<>\"\" AND @hadCreateRoutinePriv = 0;\n "
"UPDATE db SET Create_routine_priv=Create_priv, Alter_routine_priv=Alter_priv, Execute_priv=Select_priv where user<>\"\" AND @hadCreateRoutinePriv = 0;\n "
"UPDATE host SET Create_routine_priv=Create_priv, Alter_routine_priv=Alter_priv, Execute_priv=Select_priv where @hadCreateRoutinePriv = 0;\n "
"\n "
"#\n "
"# Add max_user_connections resource limit\n "
"#\n "
"ALTER TABLE user ADD max_user_connections int(11) unsigned DEFAULT '0' NOT NULL AFTER max_connections;\n "
"\n "
"#\n "
"# user.Create_user_priv\n "
"#\n "
"\n "
"SET @hadCreateUserPriv:=0;\n "
"SELECT @hadCreateUserPriv:=1 FROM user WHERE Create_user_priv LIKE '%';\n "
"\n "
"ALTER TABLE user ADD Create_user_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Alter_routine_priv;\n "
"ALTER TABLE user MODIFY Create_user_priv enum('N','Y') COLLATE utf8_general_ci DEFAULT 'N' NOT NULL AFTER Alter_routine_priv;\n "
"UPDATE user LEFT JOIN db USING (Host,User) SET Create_user_priv='Y'\n "
"  WHERE @hadCreateUserPriv = 0 AND\n "
"        (user.Grant_priv = 'Y' OR db.Grant_priv = 'Y');\n "
"\n "
"#\n "
"# procs_priv\n "
"#\n "
"\n "
"ALTER TABLE procs_priv\n "
"  ENGINE=MyISAM,\n "
"  CONVERT TO CHARACTER SET utf8 COLLATE utf8_bin;\n "
"\n "
"ALTER TABLE procs_priv\n "
"  MODIFY Proc_priv set('Execute','Alter Routine','Grant')\n "
"    COLLATE utf8_general_ci DEFAULT '' NOT NULL;\n "
"\n "
"ALTER IGNORE TABLE procs_priv\n "
"  MODIFY Routine_name char(64)\n "
"    COLLATE utf8_general_ci DEFAULT '' NOT NULL;\n "
"\n "
"ALTER TABLE procs_priv\n "
"  ADD Routine_type enum('FUNCTION','PROCEDURE')\n "
"    COLLATE utf8_general_ci NOT NULL AFTER Routine_name;\n "
"\n "
"ALTER TABLE procs_priv\n "
"  MODIFY Timestamp timestamp(14) AFTER Proc_priv;\n "
"\n "
"#\n "
"# proc\n "
"#\n "
"\n "
"# Correct the name fields to not binary, and expand sql_data_access\n "
"ALTER TABLE proc MODIFY name char(64) DEFAULT '' NOT NULL,\n "
"                 MODIFY specific_name char(64) DEFAULT '' NOT NULL,\n "
"                 MODIFY sql_data_access\n "
"                        enum('CONTAINS_SQL',\n "
"                             'NO_SQL',\n "
"                             'READS_SQL_DATA',\n "
"                             'MODIFIES_SQL_DATA'\n "
"                            ) DEFAULT 'CONTAINS_SQL' NOT NULL,\n "
"                 MODIFY body longblob DEFAULT '' NOT NULL,\n "
"                 MODIFY sql_mode\n "
"                        set('REAL_AS_FLOAT',\n "
"                            'PIPES_AS_CONCAT',\n "
"                            'ANSI_QUOTES',\n "
"                            'IGNORE_SPACE',\n "
"                            'NOT_USED',\n "
"                            'ONLY_FULL_GROUP_BY',\n "
"                            'NO_UNSIGNED_SUBTRACTION',\n "
"                            'NO_DIR_IN_CREATE',\n "
"                            'POSTGRESQL',\n "
"                            'ORACLE',\n "
"                            'MSSQL',\n "
"                            'DB2',\n "
"                            'MAXDB',\n "
"                            'NO_KEY_OPTIONS',\n "
"                            'NO_TABLE_OPTIONS',\n "
"                            'NO_FIELD_OPTIONS',\n "
"                            'MYSQL323',\n "
"                            'MYSQL40',\n "
"                            'ANSI',\n "
"                            'NO_AUTO_VALUE_ON_ZERO',\n "
"                            'NO_BACKSLASH_ESCAPES',\n "
"                            'STRICT_TRANS_TABLES',\n "
"                            'STRICT_ALL_TABLES',\n "
"                            'NO_ZERO_IN_DATE',\n "
"                            'NO_ZERO_DATE',\n "
"                            'INVALID_DATES',\n "
"                            'ERROR_FOR_DIVISION_BY_ZERO',\n "
"                            'TRADITIONAL',\n "
"                            'NO_AUTO_CREATE_USER',\n "
"                            'HIGH_NOT_PRECEDENCE'\n "
"                            ) DEFAULT '' NOT NULL,\n "
"                 DEFAULT CHARACTER SET utf8;\n "
"\n "
"# Correct the character set and collation\n "
"ALTER TABLE proc CONVERT TO CHARACTER SET utf8;\n "
"# Reset some fields after the conversion\n "
"ALTER TABLE proc  MODIFY db\n "
"                         char(64) collate utf8_bin DEFAULT '' NOT NULL,\n "
"                  MODIFY definer\n "
"                         char(77) collate utf8_bin DEFAULT '' NOT NULL,\n "
"                  MODIFY comment\n "
"                         char(64) collate utf8_bin DEFAULT '' NOT NULL;\n "
"\n "
"# Activate the new, possible modified privilege tables\n "
"# This should not be needed, but gives us some extra testing that the above\n "
"# changes was correct\n "
"\n "
"flush privileges;\n "
"\
"};
