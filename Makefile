ZMK_CONFIG_PATH:=$(HOME)/github_repos/zmk-config/config/
ZMK_PATH:=$(HOME)/github_forks/zmk/
DOCKER_IMAGE:=zmkfirmware/zmk-build-arm
DOCKER_TAG:=3.0
DOCKER_BUILD_CMD:=docker run -v $(ZMK_PATH)zephyr:/zephyr -v $(ZMK_PATH)app:/app $(DOCKER_IMAGE):$(DOCKER_TAG) west


pre_req:=. $(ZMK_PATH).venv/bin/activate; cd $(ZMK_PATH)app/;

prep_zmk: ;
	$(pre_req) \
	cd $(ZMK_PATH); \
	echo "--- Pulling latest ZMK Firmware git changes..." &&\
	git pull &&\
	echo "--- Updating ZMK / Zephyr code..." &&\
	west init -l $(ZMK_PATH)app/ ;\
	west update &&\
	west zephyr-export

docker_prep_zmk: ;
	cd $(ZMK_PATH); \
	echo "--- Pulling latest ZMK Firmware git changes..." &&\
	git pull &&\
	echo "--- Updating ZMK / Zephyr code..." &&\
	$(DOCKER_BUILD_CMD) init -l $(ZMK_PATH)app/ &&\
	$(DOCKER_BUILD_CMD) update &&\
	$(DOCKER_BUILD_CMD) zephyr-export

build_ferris: ;
	# NOTE: Trailing slash runs the commands in the same shell/venv!
	$(pre_req) \
	echo "--- Building Ferris (ARM) board..." &&\
	west build -p -d build/ferris --board ferris_rev02 -- -DZMK_CONFIG=$(ZMK_CONFIG_PATH)

docker_build_ferris: ;
	# NOTE: Trailing slash runs the commands in the same shell/venv!
	echo "--- Building Ferris (ARM) board..." &&\
	docker run $(DOCKER_IMAGE):$(DOCKER_TAG) west build -p -d build/ferris --board ferris_rev02 -- -DZMK_CONFIG=$(ZMK_CONFIG_PATH)

flash_ferris: ;
	$(pre_req) \
	west flash -d build/ferris

docker_flash_ferris: ;
	docker run $(DOCKER_IMAGE):$(DOCKER_TAG) west flash -d build/ferris

build_cradio: ;
	$(pre_req) \
	echo "--- Building Cradio (Sweep) LHS shield for Nice!Nano board..." &&\
	west build -p -d build/cradio/left/ --board nice_nano -- -DSHIELD=cradio_left -DZMK_CONFIG=$(ZMK_CONFIG_PATH) && \
	echo "--- Building Cradio (Sweep) RHS shield for Nice!Nano board..." &&\
	west build -p -d build/cradio/right/ --board nice_nano -- -DSHIELD=cradio_right -DZMK_CONFIG=$(ZMK_CONFIG_PATH)

docker_build_cradio: ;
	echo "--- Building Cradio (Sweep) LHS shield for Nice!Nano board..." &&\
	docker run $(DOCKER_IMAGE):$(DOCKER_TAG) west build -p -d build/cradio/left/ --board nice_nano -- -DSHIELD=cradio_left -DZMK_CONFIG=$(ZMK_CONFIG_PATH) && \
	echo "--- Building Cradio (Sweep) RHS shield for Nice!Nano board..." &&\
	docker run $(DOCKER_IMAGE):$(DOCKER_TAG) west build -p -d build/cradio/right/ --board nice_nano -- -DSHIELD=cradio_right -DZMK_CONFIG=$(ZMK_CONFIG_PATH)

build_all: prep_zmk build_ferris build_cradio
build_all_34: prep_zmk build_ferris build_cradio
docker_build_all: docker_build_ferris docker_build_cradio
docker_build_all_34: docker_build_ferris docker_build_cradio
