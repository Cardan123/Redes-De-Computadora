Examen = function (GUI) {

  //todo esto debe ir en la clase pregunta
  this.preguntas = new Array();
  this.preguntasPlantilla = new Array();
  this.respuestasPregunta = new Array();
  this.calificacionPregunta = new Array();
  
  this.calificacion = 0;
  
  this.descripcion = "";       
  this.titulo = "";            
  this.respuestasUsuario = 0;  
  this.preguntaActual = 0; 
  this.GUI = GUI;
 
}

Examen.prototype.cargarDatosExamen = function (URL) {

	var exaObj = this;

	var examen_xml = new XML();
	examen_xml.ignoreWhite = true;
	examen_xml.load(URL);

  	examen_xml.onLoad = function () {

    	exaObj.setTitulo(this.firstChild.attributes.TITULO);
		exaObj.setDescripcion(this.firstChild.attributes.DESCRIPCION);
	
    	var nodosPreguntas = this.firstChild.childNodes;
    
		for (var i=0; i < nodosPreguntas.length; i++) {
			exaObj.agregaPregunta(nodosPreguntas[i].firstChild.nodeValue);
			exaObj.agregaPreguntaPlantilla(nodosPreguntas[i].attributes.PLANTILLA);
		}
	}
	
}

Examen.prototype.comenzarExamen = function () {
  this.preguntaActual = 0;
  this.respuestasUsuario = 0;
  
  //mostrar primera pregunta
  this.setPreguntaActual(0);
  
}

Examen.prototype.setTitulo = function (titulo) {
  this.titulo = titulo;
//  trace("dentro de setTitulo: "+this.titulo);
}

Examen.prototype.getTitulo = function () {
  //  trace("dentro de getTitulo: "+this.titulo);
  return this.titulo == undefined ? "Untitled Quiz" : this.titulo;
}

Examen.prototype.setDescripcion = function (desc) {
  this.descripcion = desc;
}

Examen.prototype.getDescripcion = function () {
  return this.descripcion == undefined ? "A Multiple Choice Quiz" : this.descripcion;
}

Examen.prototype.calificar = function () {


}

Examen.prototype.setPreguntaActual = function (index) {
  // If index is not a valid integer, abort.
  if (typeof index != "number" || Math.floor(index) != index) {
  	trace("error");
    return;
  }
		
	
  // Bring out-of-range index values into legal range.
  if (index > this.getNumeroPreguntas() - 1) {
    this.preguntaActual = this.getNumeroPreguntas() - 1;
  } else if (index < 0) {
    this.preguntaActual = 0;
  } else {
      this.preguntaActual = index;
  }

  //cargamos la pregunta
  var cadena = this.preguntasPlantilla[index];
  
  cadena += "?pregunta_xml=";
  
  cadena += this.preguntas[index];
  
  cadena += "&respuesta=" + this.respuestasPregunta[index];

  this.GUI.pregunta_mc.loadMovie(cadena);
}

Examen.prototype.descargarPreguntaActual = function () {
   this.GUI.pregunta_mc.unloadMovie();
}


Examen.prototype.getPreguntaActual = function () {
  return this.preguntaActual;
}

Examen.prototype.getRespuestasUsuario = function () {
  return this.respuestasUsuario;
}

Examen.prototype.setRespuestasUsuario = function (nuevoNumero) {
  this.respuestasUsuario = nuevoNumero;
}

Examen.prototype.getPreguntaAt = function (index) {
  return this.preguntas[index];
}

Examen.prototype.getNumeroPreguntasCorrectas = function () {
  var num = 0;
  
    
  for(var i=0 ; i<this.calificacionPregunta.length ; i++)
    if(this.calificacionPregunta[i] == "Correcto")
	  num++;
	
    
  return num;
}

Examen.prototype.getNumeroPreguntasIncorrectas = function () {
  var num = 0;
  for(var i=0 ; i<this.calificacionPregunta.length ; i++)
    if(this.calificacionPregunta[i] == "Incorrecto")
	  num++;
	  
  return num;
}

Examen.prototype.calificarExamen = function () {

  this.calificacion = (this.getNumeroPreguntasCorrectas() * 10)/this.getNumeroPreguntas();
  
}

Examen.prototype.getCalificacionExamen = function () {
	
  return this.calificacion;
  
}


Examen.prototype.getNumeroPreguntas = function () {
  return this.preguntas.length;
}


Examen.prototype.estaTerminado = function () {
  return this.getRespuestasUsuario() == this.getNumeroPreguntas();
}

Examen.prototype.agregaPregunta = function (preg) {
   this.preguntas.push(preg);
}

Examen.prototype.agregaPreguntaPlantilla = function (preg) {
   this.preguntasPlantilla.push(preg);
}


Examen.prototype.sigPregunta = function () {
	if(this.getPreguntaActual()<(this.getNumeroPreguntas()-1)){
      this.descargarPreguntaActual();
	  this.setPreguntaActual(this.getPreguntaActual() + 1);
	  }
}

Examen.prototype.iniPregunta = function () {
	if(this.getPreguntaActual()>0){
	this.descargarPreguntaActual();
	this.setPreguntaActual(0);
	}
}

Examen.prototype.finPregunta = function () {
	  if(this.getPreguntaActual()<(this.getNumeroPreguntas()-1)){
	  this.descargarPreguntaActual();
	  this.setPreguntaActual(this.getNumeroPreguntas()-1);
	  }
}


Examen.prototype.antPregunta = function () {
	if(this.getPreguntaActual()>0){
	this.descargarPreguntaActual();
	  this.setPreguntaActual(this.getPreguntaActual() - 1);
	  }
}

Examen.prototype.setRespuestaPregunta = function(respuesta,index){
   
  if(index != undefined)
  {
	  if (typeof index != "number" || Math.floor(index) != index) {
  			trace("error");
		    return;
	  }
  }
  
  if (typeof respuesta != "string") {
  	trace("error");
    return;
  }
    
  if(index == undefined){
  		this.respuestasPregunta[this.getPreguntaActual()] = respuesta;
  }
  else
		this.respuestasPregunta[index] = respuesta;
}

Examen.prototype.getRespuestaPregunta = function(index){
  // If index is not a valid integer, abort.
  if(index != undefined)
	  if (typeof index != "number" || Math.floor(index) != index) {
  		trace("error");
	    return;
	  }
  
  if (index > this.getNumeroPreguntas() - 1) {
    index = this.getNumeroPreguntas() - 1;
  } else if (index < 0) {
    index = 0;
	  
}
	
if(index == undefined)
	  	return this.respuestasPregunta[this.getPreguntaActual()];
  else
		return this.respuestasPregunta[index];
}

Examen.prototype.setCalificacionPregunta = function (calificacion,index) {

  if(index != undefined)
  {
	  if (typeof index != "number" || Math.floor(index) != index) {
  			trace("error");
		    return;
	  }
  }
  
  if (typeof calificacion != "string") {
  	trace("error");
    return;
  }

  if (calificacion != "Correcto" && calificacion != "Incorrecto") {
  	trace("error");
    return;
  }
    
  if(index == undefined){
  		this.calificacionPregunta[this.getPreguntaActual()] = calificacion;
		this.GUI.feedback_txt.text = this.calificacionPregunta[this.getPreguntaActual()];
		}
  else
		this.calificacionPregunta[index] = calificacion;
}

Examen.prototype.getCalificacionPregunta = function (index) {
	
  if(index != undefined)
  {
	  if (typeof index != "number" || Math.floor(index) != index) {
  			trace("error");
		    return;
	  }
  }
  
  if(index == undefined){
  		return this.calificacionPregunta[this.getPreguntaActual()];
  }
  else
		return this.calificacionPregunta[index];
}
