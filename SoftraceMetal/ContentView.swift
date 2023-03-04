//
//  ContentView.swift
//  SoftraceMetal
//
//  Created by Carter Thompson on 3/2/23.
//

import SwiftUI

//Color Schemes
let background_C = Color("Background")
let text_C = Color("Text")
let accent_C = Color("Accent")
let top_C = Color("Top")

struct ContentView: View
{
    @State var tabSelection = 1
    
    var body: some View
    {
        //App Base
        VStack()
        {
            HStack()
            {
                Spacer()
                
                Button("Options")
                {
                    tabSelection = 1
                }
                .foregroundColor(text_C)
                .font(.system(size: 12))
                .controlSize(.regular)
                .shadow(radius: 4)
                
                Spacer()
                
                Button("Render")
                {
                    tabSelection = 2
                }
                .foregroundColor(text_C)
                .font(.system(size: 12))
                .shadow(radius: 4)
                
                Spacer()
                
                Button("Export")
                {
                    tabSelection = 3
                }
                .foregroundColor(text_C)
                .font(.system(size: 12))
                .shadow(radius: 4)
                
                Spacer()
                
            }
            .padding(20)
            .frame(maxWidth: .infinity)
            .background(top_C)
            
            //Pages
            OptionPage(toggle: $tabSelection)
            RenderingPage(toggle: $tabSelection)
            ExportPage(toggle: $tabSelection)
        }
            .frame(maxWidth: 600, maxHeight: 400)
            .background(background_C)
            .border(accent_C, width: 3)
    }
}

struct ContentView_Previews: PreviewProvider
{
    static var previews: some View
    {
        Group
        {
            ContentView().environment(\.colorScheme, .dark)
            ContentView().environment(\.colorScheme, .light)
        }
    }
}


// Option Body
struct OptionPage : View
{
    @Binding var toggle: Int
    
    var body : some View
    {
        VStack
        {
            if(toggle == 1)
            {
                VStack()
                {
                        // Title
                        Text("Rendering Options")
                        .padding(30)
                        .font(.system(size: 40))
                        .foregroundColor(text_C)
                        
                        // Options
                        VStack()
                        {
                            // Primary Shape Settings
                            Text("Primary Shape")
                            .foregroundColor(text_C)
                            
                            HStack()
                            {
                                
                            }
                            
                            // Background Shape Settings
                            Text("Background Scenery")
                            .foregroundColor(text_C)
                            
                            HStack()
                            {
                                
                            }
                        }
                    }
                    .padding()
                    .frame(maxWidth: .infinity, maxHeight: .infinity)
            }
        }
    }
}

// Rendering Body
struct RenderingPage : View
{
    @Binding var toggle: Int
    
    
    var body : some View
    {
        VStack
        {
            if(toggle == 2)
            {
                VStack()
                {
                    // Title
                    Text("Render")
                    .padding(10)
                    .font(.system(size: 23))
                    .foregroundColor(text_C)
                    
                    // Render Video
                    VStack()
                    {
                        Button("Render")
                        {
                            RenderImage()
                        }
                    }
                    .padding(30)
                    .frame(maxWidth: .infinity, maxHeight: .infinity)
                    
                }
                .padding()
                .frame(maxWidth: .infinity, maxHeight: .infinity)
            }
        }
    }
}

// Export  Body
struct ExportPage : View
{
    @Binding var toggle: Int
    
    
    var body : some View
    {
        VStack()
        {
            if(toggle == 3)
            {
                VStack()
                {
                    // Title
                    Text("Export")
                    .padding(10)
                    .font(.system(size: 23))
                    .foregroundColor(text_C)
                    
                    // Export Options
                    VStack()
                    {
                        
                    }
                    .padding(30)
                    .frame(maxWidth: .infinity, maxHeight: .infinity)
                    
                }
                .padding()
                .frame(maxWidth: .infinity, maxHeight: .infinity)
            }
        }
    }
}

// Calls the Rendering Function
func RenderImage()
{
    writeScene()
    renderImage()
}
