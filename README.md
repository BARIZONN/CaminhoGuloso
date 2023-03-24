# CaminhoGuloso
Projeto de graduação para disciplina de AEDS


# Descrição

O algoritmo do caminho guloso visa percorrer uma matriz passando pelos maiores números de uma determinada posição. Nesse
projeto as matrizes e suas dimensões são obtidas através da leitura de um arquivo. O usuário deve então determinar a posição inicial
e o programa então processa o caminho, armazena o percurso e a soma dos valores em cada posição percorrida, sendo esses valores exibidos
no fim da execução do programa.


# Algoritmo

* Ler "input.txt", que contém n matrizes quadradas de tamanho x
 <img  src="https://github.com/BARIZONN/CaminhoGuloso/blob/main/img/Untitled.png"> 
* Obter a dimensão da matriz na primeira linha do arquivo
* Obter a posição inicial através do input do usu[ario
* Processar o caminho a ser percorrido
* Substituir por 0 as casas percorridas
* Caso haja mais matrizes repetir o processo acima até processar todas
* Imprimir na tela o caminho percorrido e a soma dos valores


# Implementação

*O codigo responsável por determinar a próxima casa é o seguinte:
 https://github.com/BARIZONN/CaminhoGuloso/blob/main/src/file.cpp#L45-L87
 https://github.com/CesarHRS/Caminho-Guloso/blob/e1eae6326a9a707efbb99abdd85b370c543367f4/src/joystick.cpp#L12-L13

	    
            
 *Casos especiais:
 *Primeira coluna:
		Nesse caso o próximo passo não pode ser esquerda ou diagonal esquerda.

             

  *Última coluna: 
		Nesse caso o próximo passo não pode ser direita ou diagonal direita.


  *Última fileira:
			Nesse caso o único passo possível é para direita e caso seja a última casa deve encerrar o programa
		ou processar a próxima matriz.

* Ao chegar na última fileira e coluna da matriz o programa imprime o caminho percorrido.
* Casa ainda exista mais matrizes no arquivo o programa repete o processo até a última.
* No final é exibido o caminho percorrido e a soma dos valores somados.


Daniel Couto Fonseca
