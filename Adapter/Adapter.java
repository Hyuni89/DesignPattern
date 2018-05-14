import java.util.*;
import java.io.*;

class OriginAPI {
	private String cn;
	public OriginAPI() {
		cn = "OriginAPI";
	}
	public void findMaterial() {
		System.out.printf("%s: find Material\n", cn);
	}
	public void makeSomething() {
		System.out.printf("%s: make Something\n", cn);
	}
	public void done() {
		System.out.printf("%s: done!\n", cn);
	}
}

class OtherAPI {
	private String cn;
	public OtherAPI() {
		cn = "OtherAPI";
	}
	public void getSome() {
		System.out.printf("%s: get Some\n", cn);
	}
	public void getSpecialThing() {
		System.out.printf("%s: get Special Thing\n", cn);
	}
	public void combineThem() {
		System.out.printf("%s: combine Them\n", cn);
	}
	public void end() {
		System.out.printf("%s: end!\n", cn);
	}
	public void coloring() {
		System.out.printf("%s: coloring\n", cn);
	}
}

class AdapterAPI extends OriginAPI {
	private OtherAPI o;
	public AdapterAPI(OtherAPI o) {
		this.o = o;
	}
	@Override
	public void findMaterial() {
		if(o != null) {
			System.out.printf("Adapter Call\n");
			o.getSome();
			o.getSpecialThing();
		}
	}
	@Override
	public void makeSomething() {
		if(o != null) {
			System.out.printf("Adapter Call\n");
			o.combineThem();
			o.coloring();
		}
	}
	@Override
	public void done() {
		if(o != null) {
			System.out.printf("Adapter Call\n");
			o.end();
		}
	}
}

class Format {
	private OriginAPI o;
	public Format(OriginAPI o) {
		this.o = o;
	}
	public void go() {
		if(o != null) {
			o.findMaterial();
			o.makeSomething();
			o.done();
		}
	}
	public void setAPI(OriginAPI o) {
		this.o = o;
	}
}

public class Adapter {
	public static void main(String[] args) {
		OriginAPI oria = new OriginAPI();
		OtherAPI otha = new OtherAPI();
		AdapterAPI adaa = new AdapterAPI(otha);
		Format f = new Format(oria);

		f.go();
		System.out.println();
		f.setAPI(adaa);
		f.go();
	}
}
