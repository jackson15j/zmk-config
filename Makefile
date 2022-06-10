ZMK_CONFIG_PATH:=$(HOME)/github_repos/zmk-config/config/
ZMK_PATH:=$(HOME)/github_forks/zmk/


pre_req:=. $(ZMK_PATH).venv/bin/activate; cd $(ZMK_PATH)app/;

build_ferris: ;
	# NOTE: Trailing slash runs the commands in the same shell/venv!
	$(pre_req) \
	echo "--- Building Ferris (ARM) board..." &&\
	west build -p -d build/ferris --board ferris_rev02 -- -DZMK_CONFIG=$(ZMK_CONFIG_PATH)

flash_ferris: ;
	$(pre_req) \
	west flash -d build/ferris

build_cradio: ;
	$(pre_req) \
	echo "--- Building Cradio (Sweep) LHS shield for Nice!Nano board..." &&\
	west build -p -d build/cradio/left/ --board nice_nano -- -DSHIELD=cradio_left -DZMK_CONFIG=$(ZMK_CONFIG_PATH) && \
	echo "--- Building Cradio (Sweep) RHS shield for Nice!Nano board..." &&\
	west build -p -d build/cradio/right/ --board nice_nano -- -DSHIELD=cradio_right -DZMK_CONFIG=$(ZMK_CONFIG_PATH)

build_all: build_ferris build_cradio
build_all_34: build_ferris build_cradio
