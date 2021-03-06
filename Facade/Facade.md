# Facade Pattern  
어떤 프로그램이나 코드, 클래스 객체에서 복잡한 동작이나 함수 호출을 간결하게 정리된 인터페이스로 제공하는 패턴을 뜻한다.  

> 예를 들어, 컴퓨터 전원이 켜지는 과정을 생각할 수 있다. 컴퓨터가 켜지는 과정은 CPU와 메인 보드, 메모리 등등 여러 요소가 일련의 동작으로 호출이 되야 컴퓨터가 정상적으로 켜진다. 여기에서 하나라도 빠지면 문제가 생길 가능성이 있거나 컴퓨터가 제대로 켜지지 않을 가능성이 있다. 하지만 매번 컴퓨터를 킬 때 마다 일련의 동작을 하나도 빠짐없이 호출하기란 어려운 일이 될 수 있다. 그렇기 때문에 일련의 동작을 하나의 인터페이스로 묶어 간단한 호출 하나로 복잡한 일련의 동작을 대신 하게 하는 것을 말한다.  

## 디자인 원칙  
- 최소 지식 원칙 또는 데메테르의 법칙을 지켜라.  
	> 정말 뗄 수 없는 관계가 아닌 이상에야 분리 시켜라.  
- 퍼사드 패턴에서 호출하는 메소드는 다음으로 제한하는 것이 좋다.  
	> - 객체 자체 메소드  
	> - 메소드에 인자로 넘어온 객체의 메소드  
	> - 그 메소드에서 생성하거나 인스턴스를 만든 객체의 메소드  
	> - 그 객체에 속하는 구성요소  
