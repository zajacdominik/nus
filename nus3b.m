while(s.BytesAvailable>0)
    fscanf(s)
end
    
% 
% for(i=0:1:2)
%     
%          fprintf(s,'sil 200 200 200');
%          pause(1);
%         
%          
%          while(s.BytesAvailable==0)
%              ;
%          end
%          
%          while(s.BytesAvailable>0)
%              fscanf(s)
%          end
%          
%          fprintf(s,'sil -200 -200 -200');
%          pause(1);
%          
%          while(s.BytesAvailable==0)
%              ;
%          end
%          
%          while(s.BytesAvailable>0)
%              fscanf(s)
%          end
%          
% 
% end

stare_a=0;
stare_b=round(500*(sin(0+120)));
stare_c=round(500*(sin(0+240)));

for(t=0:0.1:6*3.14) % 2*3.14 = pelen sin
    
    
         a=round(500*(sin(t)));
         b=round(500*(sin(t+120)));
         c=round(500*(sin(t+240)));
         fprintf(s,'sil %d %d %d \n', [a-stare_a,b-stare_b,c-stare_c]);
        
         
         while(s.BytesAvailable==0)
             ;
         end
         
         while(s.BytesAvailable>0)
             fscanf(s)
         end
         
         stare_a=a;
         stare_b=b;
         stare_c=c;
         
      
end

