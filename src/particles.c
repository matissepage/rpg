/*
** EPITECH PROJECT, 2020
** particles.c
** File description:
** particles.c
*/

#include "rpg.h"


void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    (void)alpha;
    particle_environment->angle_min = angle.x;
    particle_environment->angle_max = angle.y;
    particle_environment->gravity = gravity;
    particle_environment->alpha = (sfUint8) 0.5;
    particle_environment->speed = SPEED;
    particle_environment->circle_shape = sfCircleShape_create();
    particle_environment->clock = sfClock_create();
}

void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos)
{
    particule->pos = pos;
    float angle = ((float)rand()/(float)(RAND_MAX)) * \
    (particle_environment->angle_max - particle_environment->angle_min) \
    + particle_environment->angle_min;
    particule->vel.x = cos(angle);
    particule->vel.y = sin(angle);
    particule->living = 1;
    particule->radius = angle;
    if (rand() % 2 == 0) {
        particule->color = sfBlue;
    } else
        particule->color = sfRed;
}

void display_particle(sfRenderWindow *window, const particle_t *particule, \
sfCircleShape *circle_shape)
{
    sfVector2f scale = {0.5, 0.5};
    if (particule->living == 1) {
        sfCircleShape_setScale(circle_shape, scale);
        sfCircleShape_setPosition(circle_shape, particule->pos);
        sfCircleShape_setFillColor(circle_shape, particule->color);
        sfCircleShape_setRadius(circle_shape, particule->radius);
        sfRenderWindow_drawCircleShape(window, circle_shape, NULL);
    }
}

void update_particle(const particle_environment_t *particle_environment, \
particle_t *particule)
{
    if (particule->living == 1) {
        particule->color.a -= (sfUint8)(5);
        particule->vel.x += particle_environment->gravity.x;
        particule->vel.y += particle_environment->gravity.y;
        particule->pos.x += particule->vel.x * SPEED;
        particule->pos.y += particule->vel.y * SPEED;
        if (particule->color.a <= 0)
            particule->living = 0;
    }
}

void add_particle(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    size_t len = 0;
    for (size_t i = 0; i < PARTICLE_MAX && len < particle_num; i++) {
        if (particule[i].living == 0) {
            len += 1;
            init_particule(particle_environment, &particule[i], pos);
        }
    }
}