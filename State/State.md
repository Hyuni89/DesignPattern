# State Pattern  
같은 동작을 하더라고 상태에 따라 전혀 다르게 동작하는 경우가 있다. 이러한 상태에 따라 다양한 동작을 만드는 패턴을 스테이트 패턴이라고 한다. 예를 들어 회사에서 퇴근하는 동작을 생각 해 보면, 기분이 좋은 경우 즐겁게 콧노래를 부르며 퇴근 할 수 있다. 너무 힘들고 지치면 최대한 빠르게 집에 갈 것이고, 기분이 좋지 않은 일이 있다면 스트레스를 풀 수 있는 장소나 행동을 하면서 퇴근 할 것이다. 스테이트 패턴은 상태에 따라 전혀 다른 클래스가 된 것과 같은 동작을 만들 수 있다.  

## 디자인 원칙  
- 스트레티지 패턴과 비슷할 수 있어 용도의 차이를 인지 할 필요가 있다.  
	> 스트래티지 패턴은 간단히 동작의 모듈화라고 이해 할 수 있고, 스테이트 패턴은 상태 중심 변화라고 이해 할 수 있다.  
