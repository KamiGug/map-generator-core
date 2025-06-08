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
            # gcc
            gdb
            pkg-config
            boost
            # googletest
            
            clang
            cppcheck

            lefthook
            typos
          ];

          shellHook = ''
            echo "Compiler: $(g++ --version | head -n1)"
            alias run="lefthook run"
            echo "Aliased 'lefthook run' to 'run'"
          '';
        };
      }
    );
}

