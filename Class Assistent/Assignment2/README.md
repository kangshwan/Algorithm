## Connected Component  
먼저 각 노드를 insert 하는 코드입니다.  
|C++|Python|
|:--:|:--:|
|![image](https://user-images.githubusercontent.com/46666296/138903145-4f297794-9dce-4cd4-8623-e921c1d750ff.png)|![image](https://user-images.githubusercontent.com/46666296/138903038-28508e79-5594-41e4-bae2-a67052ed38a1.png)|  


여기서는 인접 리스트로 그래프를 구현하였습니다.  
인접행렬로 구현하여도 무방합니다.  

|C++|Python|
|:--:|:--:|
|![image](https://user-images.githubusercontent.com/46666296/138903596-a255604c-799c-49d1-9394-12151997971d.png)|![image](https://user-images.githubusercontent.com/46666296/138903863-8c83e9f9-d8fe-4cab-8eee-cea2a7b74baa.png)|  

그래프가 여러개의 서브 그래프로 이루어져 있을 수 있기 때문에, 모든 노드에 대해서 BFS를 실행합니다.  
만일 방문한 적이 있는 노드라면 ```이미 다른 노드의 BFS를 통해서 방문이 되었다면``` 방문하지 않습니다.  

|C++|Python|
|:--:|:--:|
|![image](https://user-images.githubusercontent.com/46666296/138907281-bbaef34a-832a-4fed-a030-b7c38e4078e0.png)|![image](https://user-images.githubusercontent.com/46666296/138907342-def9597d-368f-4976-aadc-b6d506ddbe66.png)|  

이후 BFS를 진행하면서, BFS가 실행되었을때 Component 1: 처럼 Component들을 구분지어주고,  
Queue안에 들어있는 값들을 pop 해줄때 마다 출력을 해줍니다.  


이렇게 되면 모든 Connected Component들을 찾을 수 있습니다.  
