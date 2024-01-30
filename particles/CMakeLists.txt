set(PROJECT particles)

set(SOURCES
    builtin_constraints.cpp
    builtin_initializers.cpp
    builtin_particle_emitters.cpp
    builtin_particle_forces.cpp
    addbuiltin_ops.cpp
    builtin_particle_ops.cpp
    builtin_particle_render_ops.cpp
    particle_sort.cpp
    particles.cpp
    psheet.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})