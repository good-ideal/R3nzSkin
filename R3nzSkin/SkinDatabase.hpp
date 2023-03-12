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
		__CN("Ĭ��С��"), __CN("�ļ�����С��"),
		__CN("����С��"), __CN("��ѩ��С��"),
		__CN("�����Ĵ�ͷ��"), __CN("��֮�ػ���С��"),
		__CN("����ϵ��С��"), __CN("��ѩ��С��[v2]"),
		__CN("�µ���С��"), __CN("С����С��"), __CN("���ص�С��")
	};

	std::vector<const char*> turret_skins{
		__CN("Ĭ�Ϸ�����[v1]"), __CN("Ĭ�Ϸ�����[v2]"),
		__CN("��ѩ�ڷ�����[v1]"), __CN("��ѩ�ڷ�����[v2]"),
		__CN("Ť�����ַ�����[v1]"), __CN("Ť�����ַ�����[v2]"),
		__CN("���޻���������[v1]"), __CN("���޻���������[v2]"),
		__CN("����ϵ�з�����"),
		__CN("�ٺ�����������"),
		__CN("����������[��ɫ]"), __CN("����������[ԭɫ]"),
		__CN("�����ŷ�����[v1]"), __CN("�����ŷ�����[v2]"),
		__CN("������Ԩ������[v1]"), __CN("������Ԩ������[v2]")
	};

	std::vector<jungle_mob_skin_info> jungle_mobs_skins{
		{
			__CN("�о�Ƥ��"),
			{ FNV("SRU_Baron") },
			{ __CN("Baron[Ĭ��]"), __CN("��ѩ���о�"), __CN("�ھ��о�"), __CN("���о�"), __CN("MSI�о�"), __CN("�µ����о�"), __CN("�ھ������о�"), __CN("����ϵ���о�") }
		},
		{
			__CN("��Buff"),
			{ FNV("SRU_Blue") },
			{ __CN("��ɫ[Ĭ��]"), __CN("����ɫ"), __CN("Ӿ���ɶ�"), __CN("����ϵ��")}
		},
		{
			__CN("��Buff"),
			{ FNV("SRU_Red") },
			{ __CN("��ɫ[Ĭ��]"), __CN("Ӿ���ɶ�"), __CN("����ϵ��") }
		},
		{
			__CN("��з"),
			{ FNV("Sru_Crab") },
			{ __CN("Scuttle[Ĭ��]"), __CN("��ʥ��[��ɫ]"), __CN("��ʥ��[��ɫ]"),  __CN("����ϵ��") }
		},
		{
			__CN("Krug [δ֪]"),
			{ FNV("SRU_Krug"), FNV("SRU_KrugMini"), FNV("SRU_KrugMiniMini") },
			{ "Krug", "Dark Krug" }
		},
		{
			__CN("F6��Ƥ��"),
			{ FNV("SRU_Razorbeak"), FNV("SRU_RazorbeakMini") },
			{ __CN("Razorbeak [Ĭ��]"), __CN("��ѩ��Ƥ��") }
		}
	};

	std::vector<specialSkin> specialSkins{
		{ FNV("Katarina"), 29, 36, { "Dagger 1", "Dagger 2", "Dagger 3", "Dagger 4", "Dagger 5", "Dagger 6" }},
		{ FNV("Renekton"), 26, 32, { "Head off", "Head on", "Fins", "Ultimate" } },
		{ FNV("MissFortune"), 16, 16, { "Scarlet fair", "Zero hour", "Royal arms", "Starswarm" } },
		{ FNV("Ezreal"), 5, 5, { "Level 1", "Level 2", "Level 3" } }
	};
};
