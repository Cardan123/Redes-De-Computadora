package paquete;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;

public class ServletXML extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out=response.getWriter();
        try
        {
        SAXBuilder builder = new SAXBuilder();
        File archivoXML = new File("archivoXML.xml");
        Document documento=builder.build(archivoXML);
        Element raiz=documento.getRootElement();
        List lista=raiz.getChildren("name");
            for(int i=0;i<lista.size();i++)
            {
             Element elemento=(Element)lista.get(i);
             String cadena=elemento.getTextTrim();
             out.println(cadena);
            }
        }
        catch(JDOMException e)
        {
        e.printStackTrace();
        }
        }
}
