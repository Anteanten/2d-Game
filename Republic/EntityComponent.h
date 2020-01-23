#ifndef ENTITYCOMPONENT_H
#define ENTITYCOMPONENT_H

class Entity;

class EntityComponent {
private:

public:
	EntityComponent() {}

	virtual void update(double dt, Entity& entity) = 0;
};

#endif // !ENTITYCOMPONENT_H
