import java.io.*;
import java.util.*;

class Pattern {
    protected String word;
    protected String prefix;
    protected String subfix;
    protected int color;

    Pattern() {
        word="Change Color";
        prefix="\33[38;5;";
        subfix="\33[0m";
        color=15;
    }
    public String getWord() {return word;}
    public String getPrefix() {return prefix;}
    public String getSubfix() {return subfix;}
    public int getColor() {return color;}
    public void printWord() {
        System.out.println(prefix+Integer.toString(color)+"m"+word+subfix);
    }
}

class upPattern extends Pattern {
    upPattern(Pattern in) {
        word=in.getWord();
        prefix=in.getPrefix();
        subfix=in.getSubfix();
        color=in.getColor()-1;
        if(color<1) {
            color=255;
        }
    }
}

class downPattern extends Pattern {
    downPattern(Pattern in) {
        word=in.getWord();
        prefix=in.getPrefix();
        subfix=in.getSubfix();
        color=in.getColor()+1;
        if(color>255) {
            color=1;
        }
    }
}

class Decorator {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        Pattern pos=new Pattern();
        char order=0;
        pos.printWord();
        while(true) {
            System.out.printf("(u/d)? ");
            String incom=br.readLine().trim();
            if(incom.length()!=0) order=incom.charAt(0);
            switch(order) {
                case 'u':
                    pos=new upPattern(pos);
                    pos.printWord();
                    break;
                case 'd':
                    pos=new downPattern(pos);
                    pos.printWord();
                    break;
                default:
                    pos.printWord();
                    break;
            }
        }
    }
}
