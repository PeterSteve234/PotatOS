#include <iostream>      // Entrada e saída padrão
#include <filesystem>    // Manipulação de arquivos e pastas (C++17)
#include <map>           // Estrutura map para associar extensões a pastas
#include <string>        // Strings em C++
#include <algorithm>     // std::transform para conversão de letras minúsculas

namespace fs = std::filesystem;

// Mapeamento de extensões para pastas correspondentes
std::map<std::string, std::string> extensoesParaPasta = {
    {".iso", "ISO"},
    {".mp3", "Musica"},
    {".wav", "Musica"},
    {".flac", "Musica"},
    {".jpg", "Imagens"},
    {".jpeg", "Imagens"},
    {".png", "Imagens"},
    {".gif", "Imagens"},
    {".bmp", "Imagens"},
    {".svg", "Imagens"},
    {".pdf", "Documentos"},
    {".docx", "Documentos"},
    {".doc", "Documentos"},
    {".odt", "Documentos"},
    {".xlsx", "Documentos"},
    {".xls", "Documentos"},
    {".pptx", "Documentos"},
    {".ppt", "Documentos"},
    {".txt", "Textos"},
    {".cpp", "CodigoFonte"},
    {".c", "CodigoFonte"},
    {".h", "CodigoFonte"},
    {".py", "CodigoFonte"},
    {".java", "CodigoFonte"},
    {".sh", "ShellScripts"},
    {".zip", "ArquivosCompactados"},
    {".rar", "ArquivosCompactados"},
    {".tar", "ArquivosCompactados"},
    {".gz", "ArquivosCompactados"},
    {".7z", "ArquivosCompactados"},
    {".mp4", "Videos"},
    {".mkv", "Videos"},
    {".avi", "Videos"},
    {".mov", "Videos"},
    {".webm", "Videos"},
    {".html", "Web"},
    {".css", "Web"},
    {".js", "Web"}
};

// Exibe extensões suportadas
void exibirExtensoesSuportadas() {
    std::cout << "\nExtensões suportadas:\n";
    for (const auto& [ext, pasta] : extensoesParaPasta) {
        std::cout << ext << " -> " << pasta << std::endl;
    }
}

// Gera um nome único se o arquivo de destino já existir
fs::path gerarNomeUnico(const fs::path& destino) {
    fs::path novoDestino = destino;
    int contador = 1;
    while (fs::exists(novoDestino)) {
        novoDestino = destino.stem().string() + "_copia" + std::to_string(contador) + destino.extension().string();
        novoDestino = destino.parent_path() / novoDestino;
        contador++;
    }
    return novoDestino;
}

// Organiza arquivos dentro do diretório fornecido, movendo para pastas correspondentes
void organizarArquivos(const std::string& caminho) {
    try {
        for (const auto& entry : fs::directory_iterator(caminho)) {
            if (fs::is_regular_file(entry)) {
                fs::path arquivo = entry.path();
                std::string ext = arquivo.extension().string();
                std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

                if (extensoesParaPasta.count(ext)) {
                    std::string pastaDestino = caminho + "/" + extensoesParaPasta[ext];
                    fs::create_directories(pastaDestino);
                    fs::path destino = pastaDestino + "/" + arquivo.filename().string();

                    if (fs::exists(destino)) {
                        destino = gerarNomeUnico(destino);
                    }

                    fs::rename(arquivo, destino);
                    std::cout << "Movido: " << arquivo << " -> " << destino << std::endl;
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

// Remove pastas vazias no caminho informado
void removerPastasVazias(const std::string& caminho) {
    try {
        for (const auto& entry : fs::directory_iterator(caminho)) {
            if (fs::is_directory(entry) && fs::is_empty(entry)) {
                fs::remove(entry);
                std::cout << "Pasta vazia removida: " << entry.path() << std::endl;
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Erro ao remover pastas vazias: " << e.what() << std::endl;
    }
}
