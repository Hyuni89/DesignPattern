import java.util.*;
import java.io.*;

public class Chain {
	public static void main(String[] args) {
		Handler a = new PosHandler(1, 0);
		Handler b = new PosHandler(2, 1);
		Handler c = new PosHandler(3, 2);

		a.setNext(b);
		b.setNext(c);

		a.handle(10);
		a.handle(239);
		a.handle(188);
		a.handle(-59);

		Handler d = new NegHandler(4, 0);
		c.setNext(d);

		a.handle(-30);
	}
}

abstract class Handler {
	protected Handler next;
	protected int bound;
	protected int num;
	public Handler(int n, int range) {
		next = null;
		bound = range;
		num = n;
	}
	abstract public void handle(int error);
	public void setNext(Handler n) {
		next = n;
	}
}

class PosHandler extends Handler {
	public PosHandler(int n, int range) {
		super(n, range);
	}
	@Override
	public void handle(int error) {
		if(error >= 0 && error / 100 == bound) {
			System.out.printf("[%d]Handler Handle it! [%d] Error Code\n", num, error);
		} else {
			if(next != null) next.handle(error);
			else System.out.printf("Who Can Handle This????\n");
		}
	}
}

class NegHandler extends Handler {
	public NegHandler(int n, int range) {
		super(n, range);
	}
	@Override
	public void handle(int error) {
		if(error < 0) System.out.printf("NegHandler Handle it! [%d] Error Code\n", error);
		else {
			if(next != null) next.handle(error);
			else System.out.printf("Who Can Handle This????\n");
		}

	}
}
