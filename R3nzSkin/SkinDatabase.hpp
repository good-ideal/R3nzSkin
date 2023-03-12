#pragma once

#include <cstdint>
#include <map>
#include <utility>
#include <vector>

#include "fnv_hash.hpp"
 
class SkinDatabase {
public:
	class skin_info {
	public:
		const char* model_name;
		std::string skin_name;
		std::int32_t skin_id;
	};

	class jungle_mob_skin_info {
	public:
		const char* name;
		std::vector<std::uint32_t> name_hashes;
		std::vector<const char*> skins;
	};

	class specialSkin {
	public:
		std::uint32_t champHash;
		std::int32_t skinIdStart;
		std::int32_t skinIdEnd;
		std::vector<const char*> gears;
	};

	void load() noexcept;

	std::map<std::uint32_t, std::vector<skin_info>> champions_skins;
	std::vector<std::pair<std::uint32_t, const char*>> wards_skins;
	
	std::vector<const char*> minions_skins{
		__CN("默认小兵"), __CN("夏季迷你小兵"),
		__CN("工程小兵"), __CN("冰雪节小兵"),
		__CN("德莱文大头兵"), __CN("星之守护者小兵"),
		__CN("电玩系列小兵"), __CN("冰雪节小兵[v2]"),
		__CN("奥德赛小兵"), __CN("小老鼠小兵"), __CN("神秘的小兵")
	};

	std::vector<const char*> turret_skins{
		__CN("默认防御塔[v1]"), __CN("默认防御塔[v2]"),
		__CN("冰雪节防御塔[v1]"), __CN("冰雪节防御塔[v2]"),
		__CN("扭曲丛林防御塔[v1]"), __CN("扭曲丛林防御塔[v2]"),
		__CN("无限火力防御塔[v1]"), __CN("无限火力防御塔[v2]"),
		__CN("电玩系列防御塔"),
		__CN("百合莲花防御塔"),
		__CN("奥术防御塔[亮色]"), __CN("奥术防御塔[原色]"),
		__CN("屠夫桥防御塔[v1]"), __CN("屠夫桥防御塔[v2]"),
		__CN("嚎哭深渊防御塔[v1]"), __CN("嚎哭深渊防御塔[v2]")
	};

	std::vector<jungle_mob_skin_info> jungle_mobs_skins{
		{
			__CN("男爵皮肤"),
			{ FNV("SRU_Baron") },
			{ __CN("Baron[默认]"), __CN("冰雪节男爵"), __CN("冠军男爵"), __CN("狂欢男爵"), __CN("MSI男爵"), __CN("奥德赛男爵"), __CN("冠军生日男爵"), __CN("国王系列男爵") }
		},
		{
			__CN("蓝Buff"),
			{ FNV("SRU_Blue") },
			{ __CN("蓝色[默认]"), __CN("深蓝色"), __CN("泳池派对"), __CN("国王系列")}
		},
		{
			__CN("红Buff"),
			{ FNV("SRU_Red") },
			{ __CN("红色[默认]"), __CN("泳池派对"), __CN("国王系列") }
		},
		{
			__CN("河蟹"),
			{ FNV("Sru_Crab") },
			{ __CN("Scuttle[默认]"), __CN("万圣节[亮色]"), __CN("万圣节[暗色]"),  __CN("国王系列") }
		},
		{
			__CN("Krug [未知]"),
			{ FNV("SRU_Krug"), FNV("SRU_KrugMini"), FNV("SRU_KrugMiniMini") },
			{ "Krug", "Dark Krug" }
		},
		{
			__CN("F6鸟皮肤"),
			{ FNV("SRU_Razorbeak"), FNV("SRU_RazorbeakMini") },
			{ __CN("Razorbeak [默认]"), __CN("冰雪节皮肤") }
		}
	};

	std::vector<specialSkin> specialSkins{
		{ FNV("Katarina"), 29, 36, { "Dagger 1", "Dagger 2", "Dagger 3", "Dagger 4", "Dagger 5", "Dagger 6" }},
		{ FNV("Renekton"), 26, 32, { "Head off", "Head on", "Fins", "Ultimate" } },
		{ FNV("MissFortune"), 16, 16, { "Scarlet fair", "Zero hour", "Royal arms", "Starswarm" } },
		{ FNV("Ezreal"), 5, 5, { "Level 1", "Level 2", "Level 3" } }
	};
};
