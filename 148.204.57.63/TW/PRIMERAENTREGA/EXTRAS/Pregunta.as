class Pregunta{
  private var _respuesta:String= "";
  private var _calificacion:String= "";
  private var _preguntaXML:String = "";
  private var _plantilla:String = "";
  //Contructor
  function Pregunta (preguntaXML:String, plantilla:String )
  {
    _preguntaXML = preguntaXML;
    _plantilla = plantilla;
	_respuesta="";
	_calificacion="";
  }
 
  public function set PreguntaXML(pregunta:String):Void 
  {
    if (typeof pregunta != "String")
    {
  	  trace("error");
      return;
    }
    _preguntaXML = pregunta;
  }

  public function get PreguntaXML():String
  { 
    return _preguntaXML; 
  }

  public function set Plantilla(plantilla:String):Void
  {
    if (typeof plantilla != "String")
    {
  	  trace("error");
      return;
    }
    _plantilla = plantilla;
  }

  public function get Plantilla():String
  { 
    return _plantilla;
  }
  
  public function set Respuesta(respuesta:String):Void
  {
    if (typeof respuesta != "String")
    {
  	  trace("error");
      return;
    }
    _respuesta = respuesta;
  }
 
  public function get Respuesta():String
  { 
    return _respuesta;
  }

  public function set Calificacion(calificacion:String):Void
  {
    if (typeof calificacion != "String")
    {
  	  trace("error");
      return;
    }
    _calificacion = calificacion;
  }

  public function get Calificacion():String
  {
    return _calificacion;
  }
}