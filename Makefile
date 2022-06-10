ZMK_CONFIG_PATH:=$(HOME)/github_repos/zmk-config/config/
ZMK_PATH:=$(HOME)/github_forks/zmk/


pre_req:=. $(ZMK_PATH).venv/bin/activate; cd $(ZMK_PATH)app/;

build_ferris: ;
	# NOTE: Trailing slash runs the commands in the same shell/venv!
	$(pre_req) \
	west build -p -d build/ferris --board ferris_rev02 -- -DZMK_CONFIG=$(ZMK_CONFIG_PATH)

flash_ferris: ;
	$(pre_req) \
	west flash -d build/ferris

build_all: build_ferris
