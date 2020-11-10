##
## EPITECH PROJECT, 2019
## makefile
## File description:
## match
##

SRC		= 		./src/main.c 													\
		 		./src/destroyer.c 												\
				./src/manage_scene.c											\
				./src/mini_lib/sprites.c										\
				./src/mini_lib/my_itc.c											\
				./src/mini_lib/vector.c											\
				./src/mini_lib/event.c											\
				./src/game/player/init_player.c 								\
				./src/game/player/draw_player.c 								\
				./src/game/loop.c 												\
				./src/init_all.c 												\
				./src/menu/menu.c												\
				./src/menu/menu_hitbox.c										\
				./src/menu/init_menu.c											\
				./src/menu/background.c											\
				./src/menu/drawspritemenu.c										\
				./src/menu/pre_play/pre_play.c									\
				./src/menu/pre_play/init_preplay.c								\
				./src/menu/pre_play/manage_interaction.c						\
				./src/menu/pre_play/set_panelrect.c								\
				./src/menu/pre_play/init_color.c								\
				./src/menu/intro_game/intro_game.c								\
				./src/menu/pre_play/save.c										\
				./src/menu/pre_play/load_save.c									\
				./src/mini_lib/get_nextline.c									\
				./src/menu/pre_play/load_save/load_save.c						\
				./src/menu/settings/settings.c									\
				./src/menu/settings/init_settings.c								\
				./src/menu/settings/interaction_settings.c						\
				./src/menu/credits/credits.c 									\
				./src/menu/buttons_animation.c 									\
				./src/menu/pre_play/init_sprite.c 								\
				./src/game/player/move_rect_player.c 							\
				./src/game/player/move_vector_player.c 							\
				./src/parsing/read_file.c 										\
				./src/game/pause_menu/pause_menu.c								\
				./src/game/pause_menu/pause_menu_draw.c							\
				./src/game/pause_menu_options/pause_menu_options.c				\
				./src/game/pause_menu_options/pause_settings_clicks.c			\
				./src/game/pause_menu_options/pause_settings_drawer.c			\
				./src/game/inventory/draw_inventory.c 							\
				./src/game/inventory/init_inventory.c 							\
				./src/fight/init_fight_all/init_fight.c 						\
				./src/fight/init_fight_all/init_hero_fight.c 					\
				./src/fight/init_fight_all/init_attack_ennemis.c 				\
				./src/fight/init_fight_all/init_ennemies_fight.c				\
				./src/fight/init_fight_all/init_attack_sprite.c 				\
				./src/fight/init_fight_all/init_button_attack.c					\
				./src/fight/display/display_fight.c								\
				./src/fight/move_atk_ennemy.c									\
				./src/fight/move_atk_hero.c										\
				./src/fight/gest_life.c											\
				./src/fight/manage_attack.c										\
				./src/fight/move_sprite.c										\
				./src/fight/loop_fight.c										\
				./src/fight/display/display_button.c							\
				./src/game/inventory/link_inventory.c 			\
				./src/game/inventory/open_inventory.c 			\
				./src/game/inventory/pars_inventory.c 			\
				./src/game/quest/manage_quest.c					\
				./src/game/quest/init_quest.c					\
				./src/game/quest/quest_draw.c					\
				./src/game/quest/event.c						\
				./src/game/quest/fill_quest.c					\
				./src/game/quest/fill_questsparse.c				\
				./src/game/quest/node_quest.c 					\
				./src/game/quest/quest_info.c					\
				./src/game/quest/init_charquest.c				\
				./src/game/quest/draw_pnj.c 					\
				./src/game/quest/pnj_interaction.c 				\
				./src/game/object/init_object.c 				\
				./src/menu/pre_play/draw.c						\
				./src/game/dialog/loop.c						\
				./src/game/dialog/init.c 						\
				./src/game/dialog/draw.c						\
				./src/change_view.c								\
				./src/game/dialog/parse_dialog.c				\
				./src/game/dialog/event.c						\
				./src/game/inventory/save_invt.c 				\
				./src/game/inventory/write_save_invt.c			\
				./src/tool.c									\
				./src/game/dialog/destroy_dialog.c				\
				./src/mini_lib/log.c							\
				./src/mini_lib/sounds.c							\
				./src/game/dialog/btn2true.c					\
				./src/menu/pre_play/load_save/load_pos.c		\
				./src/game/waiting_screen/init_waiting_screen.c \
				./src/menu/pre_play/load_save/save_pos.c		\
				./src/game/pop_up/notif.c						\
				./src/game/quest/quest_attribute/init.c			\
				./src/game/quest/quest_attribute/check.c		\
				./src/game/minimap.c							\
				./src/menu/intro_game/init.c					\
				./src/destroy/destroy_all.c						\
				./src/game/inventory/add_item_invt.c 			\
				./src/game/inventory/check_item.c 				\
				./src/game/player/find_playertxt.c 				\
				./src/game/player/init_maptxt.c 				\
				./src/game/player/moove_playertxt.c 			\
				./src/game/dialog/set_data.c 					\
				./src/game/quest/id_quest/quest1.c 				\
				./src/game/quest/id_quest/manage_questactive.c 	\
				./src/game/quest/node.c						 	\
				./src/game/quest/move_pnj.c 					\
				./src/game/dialog/rendrequest.c 				\
				./src/game/conditionrenduquete/check_conditionrendu.c	\
				./src/game/quest/display_linkedanim.c			\
				./src/game/chest/init.c							\
				./src/game/chest/display.c						\
				./src/game/chest/backend.c						\
				./src/game/chest/node.c							\
				./src/str_to_array.c							\
				./src/game/enter_cheat.c						\
				./src/game/player/animation.c					\
				./src/game/shop/shop.c							\
				./src/game/shop/init_shop.c						\
				./src/game/shop/draw_shop.c						\
				./src/game/shop/pnj_shop.c						\
				./src/game/shop/buy_item.c						\
				./src/game/shop/shop_infos.c					\
				./src/game/player/ui_player.c 					\
				./src/game/player/moove_ui.c 					\
				./src/game/inventory/set_object.c 				\
				./src/init_map_other.c 							\
				./src/game/dialog/btn2true2.c 					\
				./src/game/dialog/event2.c 						\
				./src/game/quest/fill_quest2.c 					\
				./src/game/mob/init_mob.c 						\
				./src/game/check_positions.c					\
				./src/game/call_fightquest.c					\
				./src/game/transi/node.c 						\
				./src/game/transi/init.c 						\
				./src/menu/how_to_play/init_htp.c				\
				./src/menu/how_to_play/draw_htp.c				\
				./src/particles.c								\
				./src/particles2.c								\
				./src/game/transi/display.c 							\
				./src/game/transi/backend.c 							\
				./src/before_callfight.c						\
				./src/game/win_loose_screens/init_win_screen.c	\
				./src/game/win_loose_screens/init_loose_screen.c\
				./src/game/win_loose_screens/draw_win.c			\
				./src/game/win_loose_screens/draw_loose.c						\
				./src/fight/init_fight_all/init_template.c					\
				./src/fight/lunch_key.c										\
				./src/fight/manage_type.c							\
				./src/fight/init_fight_all/init_button_type.c		\
				./src/game/mob/sendmonster.c						\

OBJ		= $(SRC:.c=.o)
CC 		= gcc
RM		= rm -f
NAME	= my_rpg
LIB		= make -C ./lib/my
TEST 	= make -C ./tests
CFLAGS	= -W -Wall -Wextra -g3 -Wno-deprecated -I./include/
CSFML	= -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system
LDFLAGS		=  -L. lib/libmy.a

### COLORS ###
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

all: 		start $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]"

$(NAME):	$(OBJ)
		@echo "$(BOLD)Creating LIB $(GREEN)[IN PROGRESS]"
			$(LIB)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML) -lm
		@echo "$(GREEN)[$(NAME)] was successfully created$(NOC)"

test_run:
			$(TEST)
		./tests/unit_tests

retest:
	$(TEST) re
	./tests/unit_tests

clean:
		$(LIB) clean
		$(RM) $(OBJ)
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
		$(RM) $(NAME)
		$(LIB) fclean
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

end:
	@echo "\033[5m\033[1m\033[32mEtat for -> $(NAME) -> compil -> OK\033[0m"

start:
	@echo "\033[5m\033[1m\033[32mWe compil your project\033[0m"

re:		fclean all

deletesave:
	rm -f ./save/character/*.txt
	rm -f ./save/inventory/*.txt