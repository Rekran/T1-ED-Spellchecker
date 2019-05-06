package Spellchecker;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    private static HashMap<String, String> dicionario = new HashMap<>(5381);

    /**
     *
     * @throws FileNotFoundException
     * @throws IOException
     */
    public static void criarDicionario() throws FileNotFoundException, IOException {

        Scanner dic = new Scanner(new FileReader("dicionario.txt"));
        while (dic.hasNext()) {
            String palavra = dic.nextLine();
            dicionario.put(palavra, palavra);
        }
        System.out.println("Tamanho do dicionario: " + dicionario.size() + " palavaras.");
    }

    /**
     *
     * @throws FileNotFoundException
     * @throws IOException
     */
    public static void pesquisar() throws FileNotFoundException, IOException {
        //adicionar o texto no ArrayList
        ArrayList<String[]> text = new ArrayList<>();
        BufferedReader br = null;
        try {
            FileReader fr = new FileReader("texto.txt");
            br = new BufferedReader(fr);

            String str;
            while ((str = br.readLine()) != null) {
                text.add(str.split("\\s|\\r\\n\\r\\n"));
            }
        } catch (IOException e) {
            System.out.println("Arquivo não encontrado!");
        } finally {
            br.close();
        }
        System.out.println(text.size());
       
        //pesquisar as palavras do texto no dicionario
        long tempoInicial = System.currentTimeMillis();
        text.stream().forEach((s) -> {
            for (String item : s) {
                if (dicionario.get(item) == null) {                      
                    System.out.println( item);
                }
            } 
        });
      
        long tempoFinal = System.currentTimeMillis();
        System.out.print("Tempo total de verificação:  ");
        System.out.println( tempoFinal - tempoInicial + "ms" );
        
    }

    
    public static void main(String[] args) throws IOException {
        criarDicionario();
        pesquisar();
    }
}
