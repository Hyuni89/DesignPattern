# Bridge Pattern  
**추상 부분**(예, 설계도)과 **구현 부분**(예, 건물)을 분리 시키는 패턴이다. 기능과 구현이 구분되어 있어서 확장하기 용이한 장접이 있으며, 언듯 보면 Strategy Pattern이나 Adapter Pattern과 비슷하 보이기도 한다. 
먼저 Strategy Pattern과의 차이로, Bridge Pattern은 추상부와 구현부를 나눈 Structural Pattern(구조적 패턴)이지만 Strategy Pattern은 동작에 중심을 둔 Behavior Pattern이다. 그리고 Strategy Pattern은 알맞는 동작을 선택, 변경하는 것을 염두하지만 Bridge Pattern은 구조를 나누고 참조와 확장에 초점이 있다.  
Adapter Pattern은 다른 인터페이스를 사용할 수 있게 해 주는 것이 초점이라면 Bridge Pattern은 같은 인터페이스 내에 구조적 분리와 확장에 초점이 있다.  
