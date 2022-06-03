;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((c-mode . ((compile-command . "cd ~/github_forks/zmk/; source .venv/bin/activate; cd app/; west build -p -d build/ferris --board ferris_rev02 -- -DZMK_CONFIG=$HOME/github_repos/zmk-config/config/ && west flash -d build/ferris")))
 (fundamental-mode . ((compile-command . "cd ~/github_forks/zmk/; source .venv/bin/activate; cd app/; west build -p -d build/ferris --board ferris_rev02 -- -DZMK_CONFIG=$HOME/github_repos/zmk-config/config/ && west flash -d build/ferris"))))
