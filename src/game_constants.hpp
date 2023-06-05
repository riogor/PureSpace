#ifndef CORE_GAME_CONSTANTS_HPP
#define CORE_GAME_CONSTANTS_HPP

#include <vector>

struct vertex {
	float x, y;

	vertex operator*(const float coef) { return vertex{x * coef, y * coef}; }

	vertex operator-(const vertex oth) { return vertex{x - oth.x, y - oth.y}; }
};

struct polygon {
	unsigned short a, b, c;
};

struct instance {
	float x, y;
	float angle;
};

const float background_scale = 1.f;
const float asteroid_scale = 0.15f;
const float player_scale = 0.15f;

const std::vector<vertex> SQUARE_VERTICES = {{0.5f, 0.5f}, {0.5f, -0.5f}, {-0.5f, -0.5f}, {-0.5f, 0.5f}};
const std::vector<vertex> BACKGROUND_VERTICES = {{1.f, 1.f}, {1.f, -1.f}, {-1.f, -1.f}, {-1.f, 1.f}};
const std::vector<vertex> SQUARE_TEXTURE_COORDS = {{1.f, 1.f}, {1.f, 0.f}, {0.f, 0.f}, {0.f, 1.f}};
const std::vector<polygon> SQUARE_POLYGONS = {{0, 1, 3}, {1, 2, 3}};

const std::vector<vertex> PLAYER_HITBOX = []() {
	std::vector<vertex> v = SQUARE_VERTICES;
	for (auto &vert : v)
		vert = vert * player_scale;
	return v;
}();

const std::vector<vertex> ASTEROID_HITBOX = []() {
	std::vector<vertex> v = SQUARE_VERTICES;
	for (auto &vert : v)
		vert = vert * asteroid_scale;
	return v;
}();

const unsigned int MAX_CHMONYA_INSTANCES_CNT = 1024;
const unsigned int MAX_ASTEROIDS_INSTANCES_CNT = 1024;

const float PLAYER_SPEED = 0.001;
const float PLAYER_ANGLE_SPEED = 0.1;

#endif // CORE_GAME_CONSTANTS_HPP