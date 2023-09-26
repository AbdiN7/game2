{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
  name = "game";
  nativeBuildInputs = with pkgs; [pkg-config cmake];
  buildInputs = with pkgs; [
    imgui
    boost
    SDL2
    SDL2_image
    glfw
  ];
  IMGUI_DIR = "${pkgs.imgui}/include/imgui";
  shellHook = ''
          cd build
          cmake ..
          cmake --build .
          cd ..
  '';
}
