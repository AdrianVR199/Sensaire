let snackbarContainer = document.querySelector("#mensaje-interactivo");
let enlaceInteractivo = document.getElementById("enlace-interactivo");
enlaceInteractivo.addEventListener("click", function () {
  let data = { message: "Mensaje mostrado " };
  snackbarContainer.MaterialSnackbar.showSnackbar(data);
});
