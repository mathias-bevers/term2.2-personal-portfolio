#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>

#include "SFML/Graphics.hpp"
#include "gameObject.h"

namespace personal_portfolio {
    class Scene {
      protected:
        std::vector<GameObject*> game_objects;
        std::string name;

      public:
        Scene();
        virtual ~Scene();

        virtual void update();
        virtual void render(sf::RenderWindow& window);

        void set_name();

        friend std::ostream& operator<<(std::ostream& stream, Scene const& scene);
    };
}
#endif