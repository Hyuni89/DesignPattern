import java.util.*;
import java.io.*;

abstract class Mind {
	abstract public void goHome();
}

class Happy extends Mind {
	@Override
	public void goHome() {
		System.out.println("Happy! Whistle! Drop the Beat!!");
	}
}

class Tired extends Mind {
	@Override
	public void goHome() {
		System.out.println("Tired... Go home as fast as possible");
	}
}

class Angry extends Mind {
	@Override
	public void goHome() {
		System.out.println("Angry!!!!!!! Punch Punch Machine, Drink Alcohol, Destory Everything!!!");
	}
}

class WayBack2Home {
	Mind m;
	public void setMind(Mind m) {
		this.m = m;
	}
	public void goHome() {
		if(m != null) m.goHome();
	}
}

class State {
	public static void main(String[] args) {
		WayBack2Home wbth = new WayBack2Home();
		wbth.setMind(new Happy());
		wbth.goHome();
		wbth.setMind(new Angry());
		wbth.goHome();
		wbth.setMind(new Tired());
		wbth.goHome();
	}
}
