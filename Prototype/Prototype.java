import java.util.*;
import java.io.*;

abstract class Monster {
	protected int x;
	protected int y;
	protected int speed;
	protected  int health;
	public Monster(int x, int y, int speed, int health) {
		this.x = x;
		this.y = y;
		this.speed = speed;
		this.health = health;
	}
	abstract public Monster clone();
	public void show() {
		System.out.printf("x[%d], y[%d], speed[%d], health[%d]\n", x, y, speed, health);
	}
}

class Ghost extends Monster {
	public Ghost(int x, int y, int speed, int health) {
		super(x, y, speed, health);
	}
	@Override
	public Monster clone() {
		Random gen = new Random();
		return new Ghost(gen.nextInt(10), gen.nextInt(10), speed, health);
	}
	@Override
	public void show() {
		System.out.printf("Ghost ");
		super.show();
	}
}

class Spawner extends Monster {
	public Spawner(int x, int y, int speed, int health) {
		super(x, y, speed, health);
	}
	@Override
	public Monster clone() {
		Random gen = new Random();
		return new Spawner(gen.nextInt(10), gen.nextInt(10), speed, health);
	}
	@Override
	public void show() {
		System.out.printf("Spawner ");
		super.show();
	}
}

public class Prototype {
	public static void main(String[] args) {
		Monster ghost = new Ghost(1, 1, 10, 50);
		Monster spawner = new Spawner(2, 2, 5, 100);
		Monster tmp;

		ghost.show();
		spawner.show();
		tmp = ghost.clone();
		tmp.show();
		tmp = spawner.clone();
		tmp.show();
		tmp = tmp.clone();
		tmp.show();
	}
}
