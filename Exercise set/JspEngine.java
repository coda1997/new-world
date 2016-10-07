package helloworld;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import javax.script.Invocable;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class Helloworld {//"without public" means it can only be access in the same package.

	public static void main(String[] args) throws ScriptException, NoSuchMethodException, IOException {
		ScriptEngineManager manager = new ScriptEngineManager();   
		ScriptEngine engine = manager.getEngineByName("javascript");     

		String jsFileName = "D:/workstations/Test01/helloworld/md5.js";   // 读取js文件   

		FileReader reader = new FileReader(jsFileName);   // 执行指定脚本   
		engine.eval(reader);   

		if(engine instanceof Invocable) {    
			Invocable invoke = (Invocable)engine;    // 调用merge方法，并传入两个参数    

			//调用hex_md5方法，
			String c = (String)invoke.invokeFunction("hex_md5", "19970429");    

			System.out.println("pwd= " + c);   
		}   

		reader.close();  
		
		
		
		
	}
	
//	Thread th1 = new Thread();

}
