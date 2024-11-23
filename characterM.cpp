//
// Created by Jinx on 24-11-23.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Character {
    string character_id;
    string role;
    double base_strength = 0;
    double base_mana = 0;
    double base_agility = 0;
    double weapon_strength = 0;
    double staff_power = 0;
    double stealth_bonus = 0;
    int level = 0;
    string equipment_type = "";

    double calculate_strength() const {
        if (role == "Warrior") return base_strength + weapon_strength;
        return base_strength;
    }

    double calculate_mana() const {
        if (role == "Mage") return base_mana + 2 * staff_power;
        return base_mana;
    }

    double calculate_agility() const {
        if (role == "Rogue") return base_agility + stealth_bonus;
        return base_agility;
    }

    double calculate_power() const {
        double strength = calculate_strength(), mana = calculate_mana(), agility = calculate_agility();
        if (role == "Warrior") return strength * 1.5 + mana * 0.5 + agility * 0.8;
        if (role == "Mage") return mana * 2.0 + strength * 0.6 + agility * 0.7;
        if (role == "Rogue") return agility * 1.8 + strength * 0.6 + mana * 0.4;
        return 0;
    }
};

unordered_map<string, Character> characters;
unordered_map<string, vector<string>> teams;

void addCharacter(string &role, string &character_id) { characters[character_id] = {character_id, role}; }

void setAttribute(const string &character_id, const string &attribute, int value) {
    if (attribute == "base_strength")characters[character_id].base_strength = value;
    else if (attribute == "base_mana") characters[character_id].base_mana = value;
    else if (attribute == "base_agility")characters[character_id].base_agility = value;
}

void createTeam(const string &team_id, const vector<string> &member_ids) { teams[team_id] = member_ids; }

void modifyTeam(const string &team_id, const string &attribute, int value) {
    for (const auto &member_id: teams[team_id])setAttribute(member_id, attribute, value);
}

void listCharacters(const string &order) {
    vector<Character> sorted_characters;
    for (const auto &[id, character]: characters) sorted_characters.push_back(character);
    if (order == "Normal")
        sort(sorted_characters.begin(), sorted_characters.end(),
             [](const Character &a, const Character &b) {
                 return stoi(a.character_id.substr(1)) < stoi(b.character_id.substr(1));
             });
    else if (order == "Power")
        sort(sorted_characters.begin(), sorted_characters.end(), [](const Character &a, const Character &b) {
            if (a.calculate_power() == b.calculate_power())
                return stoi(a.character_id.substr(1)) < stoi(b.character_id.substr(1));
            return a.calculate_power() > b.calculate_power();
        });
    for (const auto &character: sorted_characters)
        cout << character.character_id << " strength " << character.calculate_strength() << " mana "
             << character.calculate_mana() << " agility " << character.calculate_agility() << endl;
}

void upgradeCharacter(const string &character_id) {
    Character &character = characters[character_id];
    if (character.level >= 5) {
        cout << "Character " << character_id << " is already at max level" << endl;
        return;
    }
    if (character.role == "Warrior") character.base_strength *= 1.1;
    else if (character.role == "Mage") character.base_mana *= 1.2;
    else if (character.role == "Rogue") character.base_agility *= 1.15;
    character.level++;
}

void equipCharacter(const string &character_id, const string &equipment_type, int value) {
    Character &character = characters[character_id];
    if (!character.equipment_type.empty() || character.staff_power || character.stealth_bonus ||
        character.weapon_strength) {
        cout << "Character " << character.character_id << " already has equipment";
        return;
    }
    if (equipment_type == "weapon" && character.role == "Warrior") character.weapon_strength = value;
    else if (equipment_type == "staff" && character.role == "Mage") character.staff_power = value;
    else if (equipment_type == "cloak" && character.role == "Rogue") character.stealth_bonus = value;
    else return;
    character.equipment_type = equipment_type;
}

void powerList() {
    vector<Character> character_list;
    for (const auto &[id, character]: characters) character_list.push_back(character);
    sort(character_list.begin(), character_list.end(),
         [](const Character &a, const Character &b) {
             return stoi(a.character_id.substr(1)) < stoi(b.character_id.substr(1));
         });
    for (const auto &character: character_list)
        cout << character.character_id << " power: " << character.calculate_power() << endl;
}

void battle(const string &id1, const string &id2) {
    double power1 = characters[id1].calculate_power(), power2 = characters[id2].calculate_power();
    if (abs(power1 - power2) / max(power1, power2) < 0.1) cout << "Draw" << endl;
    else if (power1 > power2)cout << id1 << " wins" << endl;
    else cout << id2 << " wins" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string command;
        cin >> command;
        if (command == "Add") {
            string role, character_id;
            cin >> role >> character_id;
            addCharacter(role, character_id);
        } else if (command == "Set") {
            string character_id, attribute;
            int value;
            cin >> character_id >> attribute >> value;
            setAttribute(character_id, attribute, value);
        } else if (command == "Team") {
            string team_id;
            cin >> team_id;
            vector<string> members;
            string member;
            while (cin >> member) {
                members.push_back(member);
                if (cin.peek() == '\n') break;
            }
            createTeam(team_id, members);
        } else if (command == "Modify") {
            string team_id, attribute;
            int value;
            cin >> team_id >> attribute >> value;
            modifyTeam(team_id, attribute, value);
        } else if (command == "List") {
            string order;
            cin >> order;
            listCharacters(order);
        } else if (command == "Upgrade") {
            string character_id;
            cin >> character_id;
            upgradeCharacter(character_id);
        } else if (command == "Equip") {
            string character_id, equipment_type;
            int value;
            cin >> character_id >> equipment_type >> value;
            equipCharacter(character_id, equipment_type, value);
        } else if (command == "PowerList") powerList();
        else if (command == "Battle") {
            string id1, id2;
            cin >> id1 >> id2;
            battle(id1, id2);
        }
    }
}