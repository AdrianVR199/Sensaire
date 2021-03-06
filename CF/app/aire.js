// Declara el objeto de "SerialPort" que se va a utilizar
var serial;
var port = 'COM5'; // variable que indica el puerto serial utilizado por el Arduino
var backgroundColor = 'rgb(0, 0, 0)'; // variable donde se almacena el color de fondo

function setup() {
 createCanvas(windowWidth, windowHeight);

 // Crea un objeto del tipo SerialPort
 serial = new p5.SerialPort();

 // Determina el método que se llama para listar los puertos seriales conectados
 serial.list();
 serial.on('list', portList);

 // Abre la conexión con el puerto donde está conectado el Arduino
 serial.open(port);

 // Determina el método que se llama cuando hay datos en el puerto
 serial.on('data', getData);
}


// Método que muestra por consola los puertos seriales conectados al PC
function portList(ports) {
 console.log('Listado de puertos seriales:');
 // recorre el listado de puertos seriales y los muestra por consola
 for (var i = 0; i < ports.length; i++) {
 	console.log(ports[i]);
 }
}

// Método que llama al recibir datos desde el puerto serial
function getData() {
   var data = serial.readStringUntil("\r\n");// lee los datos desde el puerto serial
   trim(data);                	// elimina los espacios en blanco al principio y final de los datos, si los hay
   if (!data) return;         	// si los datos leídos están vacíos no hace nada
   console.log(data);         	// muestra los datos leídos
}
