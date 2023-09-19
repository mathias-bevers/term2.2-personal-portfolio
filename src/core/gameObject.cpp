#include "gameObject.h"
#include "../tools/easylogging++.h"
#include "../tools/settings.h"

namespace personal_portfolio {
    GameObject::GameObject(std::string sprite_path) : GameObject::GameObject(sprite_path, sf::Vector2f(0, 0))
    {
    }

    GameObject::GameObject(std::string sprite_path, sf::Vector2f position)
    {
        this->sprite_path = PATH_IMAGES + sprite_path;
        if (!texture.loadFromFile(this->sprite_path)) {
            std::string cwd = get_working_dir();

            if (!cwd.empty()) {
                LOG(ERROR) << "Could not load texture with path: " << cwd << "/" << sprite_path;
            }
            else {
                LOG(ERROR) << "Could not load image or path";
            }

            exit(1);
            return;
        }

        sprite = sf::Sprite(texture);
        sprite.setOrigin(0.5, 0.5);
        sprite.setPosition(position);
    }

    void GameObject::render(sf::RenderWindow& window) const { window.draw(sprite); }

    void GameObject::update() { }

    sf::Vector2f GameObject::get_size() const
    {
        const float x = sprite.getTexture()->getSize().x * sprite.getScale().x;
        const float y = sprite.getTexture()->getSize().y * sprite.getScale().y;
        return sf::Vector2f(x, y);
    }

    void GameObject::set_size(const sf::Vector2f size)
    {
        sf::Vector2f scale(1, 1);
        scale.x = size.x / sprite.getTexture()->getSize().x;
        scale.y = size.y / sprite.getTexture()->getSize().y;
        sprite.setScale(scale);
    }

    const sf::Vector2f GameObject::get_position() const { return sprite.getPosition(); }

    void GameObject::set_position(const sf::Vector2f position) { sprite.setPosition(position); }

    const sf::Color GameObject::get_color() const { return sprite.getColor(); }

    void GameObject::set_color(const sf::Color color) { sprite.setColor(color); }

    GameObject::~GameObject() = default;
}