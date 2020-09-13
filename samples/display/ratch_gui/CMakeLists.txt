# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(lvgl)

FILE(GLOB app_sources src/*.c src/gui/*.c src/gui/fonts/*.c src/menu/*.c)
zephyr_include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/src/
    )
target_sources(app PRIVATE ${app_sources})
