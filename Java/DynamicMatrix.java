import java.util.*;

public class MatrizDinamica{

    public static void main(String [] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int line, column;

        System.out.println("First Matrix");
        System.out.print("Enter the number of lines: ");
        line = sc.nextInt();
        System.out.print("Enter the number of columns: ");
        column = sc.nextInt();
        Matrix matrix1 = new Matrix(line, column);
        System.out.println("Type the elemnts of your matrix, like this:");
        System.out.println("1 2 3");
        System.out.println("4 5 6");
        System.out.println("7 8 9\n");
        matrix1.inserir(line, column, sc);

        System.out.println("Second Matrix");
        System.out.print("Enter the number of lines: ");
        line = sc.nextInt();
        System.out.print("Enter the number of columns: ");
        column = sc.nextInt();
        Matrix matrix2 = new Matrix(line, column);
        System.out.println("Type the elemnts of your matrix, like this:");
        System.out.println("1 2 3");
        System.out.println("4 5 6");
        System.out.println("7 8 9 \n");
        matrix2.inserir(line, column, sc);


        System.out.println("Main Diagonal of the First Matrix");
        matrix1.printMainDiagonal();
        System.out.println("Secondary Diagonal of the First Matrix");
        matrix1.printSecondaryDiagonal();
        System.out.println("Main Diagonal of the Second Matrix");
        matrix2.printMainDiagonal();
        System.out.println("Secondary Diagonal of the First Matrix");
        matrix2.printSecondaryDiagonal();

        System.out.println("The sum of matrix1 + matrix2 is:");
        matrix1.sum(matrix2);
        Matrix multi = new Matrix(line, column);
        multi = matrix1.multiplication(matrix2);
        System.out.println("The product of matrix1 * matrix2 is:");
        multi.printMatrix();

    }
}

    class CellMatrix {

        public int element;
        public CellMatrix bottom, superior, left, right;

        public CellMatrix(){
            this(0, null, null, null, null);
        }
    
        public CellMatrix(int element){
            this(element, null, null, null, null);
        }
    
        public CellMatrix(int element, CellMatrix bottom, CellMatrix sup, CellMatrix left, CellMatrix right){
            this.element = element;
            this.bottom = bottom;
            this.superior = sup;
            this.left = left;
            this.right = right;
        }

    }

    class Matrix{

        protected CellMatrix begin;
        protected int line; 
        protected int column;

        Matrix(){
            this(3,3);
        }

        Matrix(int line, int column){

            this.line = line;
            this.column = column;
            this.begin = new CellMatrix(0);
            CellMatrix pointer = begin;
            CellMatrix pointerAux = begin;
            CellMatrix ponteiroAuxcolumn = begin;

            for(int i = 1; i < column; i++){ 
                pointer.right = new CellMatrix(0);
                pointer.right.left = pointer;
                pointer = pointer.right;
            }

            pointer = begin;
            for(int i = 1; i < line; i++){
                pointer.bottom = new CellMatrix(0);
                pointer.bottom.superior = pointer;
                pointer = pointer.bottom;
            }

            CellMatrix pointerColumn = begin.right;
            CellMatrix pointerLine = begin.bottom;
            pointerAux = pointerLine;
            ponteiroAuxcolumn = pointerColumn;
            for(int i = 1; i < line; i++){
                for(int k = 1; k < column; k++){
                    pointerLine.right = new CellMatrix(0);
                    pointerColumn.bottom = pointerLine.right;
                    pointerLine.right.left = pointerLine;
                    pointerLine.right.superior = pointerColumn;
                    pointerLine = pointerLine.right;
                    if(pointerColumn.right != null)
                    pointerColumn = pointerColumn.right;
                }
                pointerColumn = ponteiroAuxcolumn;
                pointerLine = pointerAux;
                if(i + 1 < line){
                    pointerLine = pointerLine.bottom;
                    pointerColumn = ponteiroAuxcolumn.bottom;
                    pointerAux = pointerAux.bottom;
                    ponteiroAuxcolumn = ponteiroAuxcolumn.bottom;
                }
            }
            
        }//End Constructor

        void printMatrix(){

            CellMatrix pointer = begin;
            CellMatrix pointerAux = begin;

            while(pointer != null){
                pointerAux = pointer;
                for(int i = 0; i < column; i++){
                    System.out.print(pointer.element +" ");
                    pointer = pointer.right;
                }
                System.out.println("");
                pointer = pointerAux;
                pointer = pointer.bottom;
            }

        }

        void insertElemnt(int line, int column, int element){

            CellMatrix pointer = begin;

            for(int i = 1; i < line; i++){
                pointer = pointer.bottom;
            }

            for(int i = 1; i < column; i++){
                pointer = pointer.right;
            }

            pointer.element = element;
        }

        void inserir(int line, int column, Scanner sc){

            String valores = "";

            sc.nextLine();

            for(int i = 1; i <= line; i++){
                valores = sc.nextLine();
                for(int j = 1; j <= column; j++){
                    String [] numeros = valores.split(" ");
                    insertElemnt(i, j, Integer.parseInt(numeros[j-1]));
                }
            }
        }

        public boolean isQuadrada(){
            return (this.line == this.column);
        }

        void printMainDiagonal(){

            CellMatrix pointer = this.begin;

            for(int i = 0; i < this.column; i++){
                System.out.print(pointer.element +" ");
                if(pointer.right != null)
                pointer = pointer.right.bottom;
            }
            System.out.println(" ");
        }

        void printSecondaryDiagonal(){

            CellMatrix pointer = this.begin;

            for(int i = 0; i < this.column; i++){
                if(pointer.right != null)
                pointer = pointer.right;
            }

            for(int i = 0; i < this.column; i++){
                System.out.print(pointer.element +" ");
                if(pointer.left != null)
                pointer = pointer.left.bottom;
            }

            System.out.println(" ");
        }

        void sum(Matrix matrix2){

            CellMatrix ponteiro1 = begin;
            CellMatrix ponteiro2 = matrix2.begin;
            CellMatrix ponteiro1Aux = ponteiro1;
            CellMatrix ponteiro2Aux = ponteiro2;
            Matrix sum = new Matrix();
            int valor = 0;

            if(this.line == matrix2.line && this.column == matrix2.column){
                sum = new Matrix(this.line, this.column);
                for(int k = 1; k <= line; k++){
                    for(int i = 1; i <= column; i++){
                        valor = ponteiro1.element + ponteiro2.element;
                        sum.insertElemnt(k, i, valor);
                        if(ponteiro1.right != null && ponteiro2.right != null){
                            ponteiro1 = ponteiro1.right;
                            ponteiro2 = ponteiro2.right;
                        }
                    }
                    //completar second line
                    ponteiro1 = ponteiro1Aux;
                    ponteiro2 = ponteiro2Aux;
                    if(k + 1 <= line){
                        ponteiro1 = ponteiro1.bottom;
                        ponteiro2 = ponteiro2.bottom;
                        ponteiro1Aux = ponteiro1;
                        ponteiro2Aux = ponteiro2;
                    }
                }
            }
            sum.printMatrix();
            System.out.println();

        }//end sum

        public Matrix multiplication(Matrix matrix2) throws Exception{

                Matrix multiplication = new Matrix(this.line, this.column);

                if(this.line == matrix2.line && this.column == matrix2.column){
                for(CellMatrix i = begin, x = multiplication.begin; x != null ; i = i.bottom, x = x.bottom){
                    for (CellMatrix lin = matrix2.begin, y = x ; y != null ; lin = lin.right, y = y.right) {
                        CellMatrix jin = lin;
                        CellMatrix hpri = i;

                        while(jin != null) {
                            y.element += jin.element * hpri.element;
                            jin = jin.bottom;
                            hpri = hpri.right;
                        }
                    }
                }
            }
                return multiplication;
        }
    }
