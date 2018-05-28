# Interpreter Pattern  
규칙을 가지고 있는 언어를 해석해주는 패턴으로 SQL 쿼리나 다양한 스크립트 언어에서 사용된다. 문법을 변경하고 확장하는데 용의하지만 복잡한 문법의 경우(문법 규칙이 많아지는 경우)에는 그에 따라 처리 클래스가 증가하여 관리하기 까다로워 질 수 있다. 이 패턴의 구조는 Composite Pattern과 유사한데 이는 언어를 쪼개 클래스에서 처리할 수 있는 단위로 나누고[(BNF, Backus-Naur Form or Backus Normal Form)](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form) 병합하며 결과를 가져오기 때문이다.  
<sub>프로그램 실행시 옵션 인자 파싱하기에 편리할 것 같다</sub>  
