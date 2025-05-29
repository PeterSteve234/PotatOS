#include <iostream>      // Entrada e saída padrão
#include <filesystem>    // Manipulação de arquivos e pastas (C++17)
#include <map>           // Estrutura map para associar extensões a pastas
#include <string>        // Strings em C++

// Apelido para namespace filesystem para facilitar o uso
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
    {".pdf", "Documentos"},
    {".docx", "Documentos"},
    {".doc", "Documentos"},
    {".xlsx", "Documentos"},
    {".xls", "Documentos"},
    {".pptx", "Documentos"},
    {".txt", "Textos"},
    {".cpp", "CodigoFonte"},
    {".c", "CodigoFonte"},
    {".h", "CodigoFonte"},
    {".py", "CodigoFonte"},
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
    {".html", "Web"},
    {".css", "Web"},
    {".js", "Web"}
    // Adicione mais extensões conforme desejar
};
