int menor = *min_element(a,a+n); // Acha o menor valor em um array de tamanho n.
int qntd = count(v.begin(),v.end(),3); // Conta quantos números 3 aparecem no vector v.
int mdc = __gcd(a,b); // Calcula o MDC entre dois números. OBS: Tomar cuidado com long long.
int qntdDeUm = __builtin_popcount(x); // Calcula o número de 1's na representação binária do x.
										// OBS: Usar __builtin_popcountll quando x for long long;
int soma = accumulate(vetor.begin(), vetor.end(), valorInicial); // Soma todos os valores do vetor com o valorInicial
iota(vetor.begin(), vetor.end(), valorInicial);                  // Preenche o vetor acumulando o valorInicial
fill(vetor.begin(), vetor.end(), valor);                         // Preenche o vetor com o valor