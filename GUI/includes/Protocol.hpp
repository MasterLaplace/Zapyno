/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy
** File description:
** Protocol
*/


#ifndef PROTOCOL_HPP_
    #define PROTOCOL_HPP_
    #include "Tiles.hpp"
    #include "Trantorian.hpp"
    #include "StringManager.hpp"
    #include "Client.hpp"
    #include <functional>

/**
 * @brief Protocol class
 *
*/
namespace Manager {
    class Protocol {
        public:
            Protocol() {
                commands["msz"] = [this](std::string &str) { msz(str); };
                commands["bct"] = [this](std::string &str) { bct(str); };
                commands["tna"] = [this](std::string &str) { tna(str); };
                commands["pnw"] = [this](std::string &str) { pnw(str); };
                commands["ppo"] = [this](std::string &str) { ppo(str); };
            }
            ~Protocol() = default;

            void parseCommand(std::string &str, std::shared_ptr<Client> client);

            /**
             * @brief map size (width, height)
             *
             * @param str  msz X Y\n
             */
            void msz(std::string &str);

            /**
             * @brief content of a tile (x, y, q0, q1, q2, q3, q4, q5, q6)
             *
             * @param str  bct X Y q0 q1 q2 q3 q4 q5 q6\n
             */
            void bct(std::string &str);

            /**
             * @brief name of all the teams
             *
             * @param str  tna N\n * nbr_teams
             */
            void tna(std::string &str);

            /**
             * @brief connection of a new player (id, x, y, orientation, level, team name)
             *
             * @param str  pnw n X Y O L N\n
             */
            void pnw(std::string &str);

            /**
             * @brief player’s position and orientation (id, x, y, orientation)
             *
             * @param str  ppo n X Y O\n
             */
            void ppo(std::string &str);
            void setMapSize(std::string &str) { _mapSize = Math::Vector(String::string_to_string_vector(str, " ")); }
            Math::Vector getMapSize() const { return _mapSize; }

            void setTrantorians(std::vector<GUI::Trantorian> trantorians) { _trantorians = trantorians; }

            std::vector<GUI::Trantorian> getTrantorians() const { return _trantorians; }

            void addTrantorian(GUI::Trantorian trantorian) { _trantorians.push_back(trantorian); }

        protected:
        private:
            std::vector<GUI::Tiles> _tiles;
            std::vector<GUI::Trantorian> _trantorians;
            Math::Vector _mapSize = {10, 10};
            std::map<const std::string /*name*/, std::function<void(std::string&)>> commands;
            std::vector<std::string /*name*/> _teams;
            unsigned _timeUnit = 100;
    };
} // namespace Manager

#endif /* !PROTOCOL_HPP_ */
