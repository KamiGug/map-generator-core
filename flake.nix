{
  description = "Map generation library for the engineering degree project";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-unstable";
    flake-utils.url = "flake-utils";
  };

  outputs = { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { inherit system; };
      in {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            cmake
            gnumake
            gdb
            
            clang
            cppcheck

            lefthook
            go-task
            typos
          ];

          shellHook = ''
            echo "Compiler: $(g++ --version | head -n1)"
            task --list
            alias task='task -s'
          '';
        };
      }
    );
}

