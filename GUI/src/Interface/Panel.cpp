/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy
** File description:
** Panel
*/

#include "../../includes/Panel.hpp"

namespace Interface {
    void Panel::updatePanel(const Math::Vector &mousePos, const bool &mousePressed) {
        for (auto &button : _buttons)
            button.animate(mousePos, mousePressed);
        for (auto &checkbox : _checkboxs)
            checkbox.animate_checkbox(mousePos, mousePressed);
        for (auto &bar : _bars)
            bar.updateState();
        if (!_sprite) return;
        auto size = _sprite->getSize();
        if (_callback == OPEN_INVENTORY && mousePressed &&
            ((mousePos.x() <= _pos.x() || mousePos.x() >= _pos.x() + size.x()) ||
            (mousePos.y() <= _pos.y() || mousePos.y() >= _pos.y() + size.y())))
            _callback = NONE;
    }

    void Panel::updatePanel(const Math::Vector &mousePos, int key, const bool &mousePressed) {
        for (auto &button : _buttons)
            button.animate(mousePos, mousePressed);
        for (auto &checkbox : _checkboxs)
            checkbox.animate_checkbox(mousePos, mousePressed);
        for (auto &input : _inputs)
            input.updateState(mousePos, key, mousePressed);
        for (auto &bar : _bars)
            bar.updateState();
        if (!_sprite) return;
        auto size = _sprite->getSize();
        if (_callback == OPEN_INVENTORY && mousePressed &&
            ((mousePos.x() <= _pos.x() || mousePos.x() >= _pos.x() + size.x()) ||
            (mousePos.y() <= _pos.y() || mousePos.y() >= _pos.y() + size.y())))
            _callback = NONE;
    }

    std::vector<CALLBACK> Panel::getCallback() {
        std::vector<CALLBACK> callback;
        for (auto &button : _buttons)
            if (button.getState() == Interface::Button::RELEASED)
                callback.push_back(button.getCallback());
        for (auto &checkbox : _checkboxs)
            if (checkbox.getState() == Interface::Checkbox::RELEASED)
                callback.push_back(checkbox.getCallback());
        return callback;
    }
} // namespace Interface
