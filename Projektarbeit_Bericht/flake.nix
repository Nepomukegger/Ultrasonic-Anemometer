{
  description = "Template for writing a thesis at the Faculty of Computer Science at Nuremberg Institute of Technology";

  inputs = {
    flake-parts.url = "github:hercules-ci/flake-parts";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = inputs@{ flake-parts, ... }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      imports = [ ];
      systems = [ "x86_64-linux" "aarch64-linux" "aarch64-darwin" "x86_64-darwin" ];
      perSystem = { config, self', inputs', pkgs, system, ... }: {

				# Development shell for using the Typst compiler
        devShells.default = pkgs.mkShellNoCC {
					packages = with pkgs; [ typst ];
				};

      };

      flake = { };
    };
}
