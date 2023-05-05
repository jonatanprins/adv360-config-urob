/*
 * 
 *;) helper.h
 *
 * Convenience macros simplifying ZMK's keymap configuration.
 * See https://github.com/urob/zmk-nodefree-config for documentation.
 */

#pragma once

#define ZMK_HELPER_STRINGIFY(x) #x

/* ZMK_BEHAVIOR */
#define ZMK_SHIFTED(name, one, two) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-mod-morph"; \
                label = ZMK_HELPER_STRINGIFY(MM_ ## name); \
                #binding-cells = <0>; \
                mods = <(MOD_LALT|MOD_RALT|MOD_LCTL|MOD_RCTL|MOD_LSFT|MOD_RSFT)>; \
                keep-mods = <(MOD_LALT|MOD_RALT|MOD_LCTL|MOD_RCTL)>; \
                bindings = <one>, <two>; \
            }; \
        }; \
    };

#define IGNORE_MODIFIER(name, one) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-mod-morph"; \
                label = ZMK_HELPER_STRINGIFY(MM_ ## name); \
                #binding-cells = <0>; \
                mods = <(MOD_LALT|MOD_RALT|MOD_LCTL|MOD_RCTL|MOD_LSFT|MOD_RSFT)>; \
                bindings = <one>, <one>; \
            }; \
        }; \
    };

