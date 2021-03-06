function cho_vektor = sum2vec(summenformel)
    
    sc = sprintf('%c %c %c %c %c',summenformel);
    array = strsplit(sc, ' ');
    disp(array);
    idx_c = find(ismember(array,"C"))
    idx_h = find(ismember(array,"H"))
    idx_o = find(ismember(array,"O"))
    
    % Count Letters 
    for i = 1:3
        if i == 1
            cho_vektor(1) = sum(array == "C");
        elseif i ==2
            cho_vektor(2) = sum(array == "H");
        else 
            cho_vektor(3) = sum(array == "O");
        end
    end
    disp("einfache suche");
    disp(cho_vektor); 
    %disp(size(array));
    if cho_vektor(1) >=1
        for i = 1:length(idx_c)
            if (size(array,2) > idx_c(i)+1) & array(idx_c(i)+1) ~= "H" & array(idx_c(i)+1) ~= "O" 
                % wenn beide danach ungleich HO zweistellige zahl
                if (size(array,2) > idx_c(i)+2) & array(idx_c(i)+2) ~= "H" & array(idx_c(i)+2) ~= "O"
                disp("zweistellig");
                %transform die beiden elemente in zahl
                nr1 = array(idx_c(i)+1);
                nr2 = array(idx_c(i)+2);
                %disp(nr1);
                %disp(nr2);
                comb = str2num(cell2mat(strcat(nr1,nr2)));
                %disp(comb);
                new_nr = cho_vektor(1) +comb -1;
                cho_vektor(1) = new_nr;
                else
                nr = str2num(cell2mat(array(idx_c(i)+1)));
                %disp(nr);
                %disp(class(nr));
                %disp(cho_vektor(1));
                new_nr = cho_vektor(1) + nr -1;
                %disp("new_nr");
                %disp(new_nr);
                cho_vektor(1) = new_nr;
                end
            end
        end
    end
    if cho_vektor(2) >=1
        %disp(idx_h);
        for i = 1:length(idx_h)
            disp(size(array,2));
            if (size(array,2) > idx_h(i)+1) & array(idx_h(i)+1) ~= "C" & array(idx_h(i)+1) ~= "O" 
                % wenn beide danach ungleich HO zweistellige zahl
                if (size(array,2) >= idx_h(i)+2) & array(idx_h(i)+2) ~= "C" & array(idx_h(i)+2) ~= "O"
                    disp("zweistellig");
                    %transform die beiden elemente in zahl
                    nr1 = array(idx_h(i)+1);
                    nr2 = array(idx_h(i)+2);
                    comb = str2num(cell2mat(strcat(nr1,nr2)));
                    new_nr = cho_vektor(2) + comb -1;
                    cho_vektor(2) = new_nr;
                else
                    nr = str2num(cell2mat(array(idx_h(i)+1)));
                    new_nr = cho_vektor(2) + nr -1;
                    cho_vektor(2) = new_nr;
                end
            end
        end
    end
    if cho_vektor(3) >=1
        for i = 1:length(idx_o)
            if (size(array,2) > idx_o(i)+1) & array(idx_o(i)+1) ~= "C" & array(idx_o(i)+1) ~= "H" & array(idx_o(i)+1) ~= "O"
                % wenn beide danach ungleich HO zweistellige zahl
                if (size(array,2) >= idx_o(i)+2) & array(idx_o(i)+2) ~= "C" & array(idx_o(i)+2) ~= "H"
                disp("zweistellig");
                %transform die beiden elemente in zahl
                nr1 = array(idx_o(i)+1);
                nr2 = array(idx_o(i)+2);
                comb = str2num(cell2mat(strcat(nr1,nr2)));
                new_nr = cho_vektor(3) +comb -1;
                cho_vektor(3) = new_nr;
                else
                nr = str2num(cell2mat(array(idx_o(i)+1)));
                new_nr = cho_vektor(3) + nr -1;
                cho_vektor(3) = new_nr;
                end
            end
        end
    end
end