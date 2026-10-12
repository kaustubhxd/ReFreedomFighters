#!/usr/bin/env python3
"""Freedom Fighters WHD/WAV sound-bank decoder.

WHD: u32 size, u32 size+8, u32 3, u32 4, then 48-byte entries, then 8 zero bytes.
Entry (12 x u32): 6, 0, format, rate, bits, pcmBytes, dataBytes, channels,
                  dataOffset, sampleFrames, blockAlign, samplesPerBlock.
format low word 0x11 = IMA ADPCM (512-byte blocks), 0x01 = 16-bit PCM,
0x1000 = an embedded Ogg Vorbis stream; bit 0x80000000 = data lives in the
root streams.wav instead of the scene's own .WAV bank.
The scene's SND file names each sound: after "<name>\0<file>.wav\0" come
u32 1, u32 ?, u32 (WHD byte offset of the entry + 1), f32 duration seconds.

usage: whd.py SCENE.WHD SCENE.WAV OUTDIR [streams.wav] [SCENE.SND]
"""
import struct, sys, os, wave, array

STEP = [7,8,9,10,11,12,13,14,16,17,19,21,23,25,28,31,34,37,41,45,50,55,60,66,73,80,88,97,107,118,130,143,157,173,190,209,230,253,279,307,337,371,408,449,494,544,598,658,724,796,876,963,1060,1166,1282,1411,1552,1707,1878,2066,2272,2499,2749,3024,3327,3660,4026,4428,4871,5358,5894,6484,7132,7845,8630,9493,10442,11487,12635,13899,15289,16818,18500,20350,22385,24623,27086,29794,32767]
IDX = [-1,-1,-1,-1,2,4,6,8]

def parse_whd(d):
    size, size8, a, b = struct.unpack_from('<4I', d, 0)
    assert size8 == len(d) and size + 8 == size8 and (a, b) == (3, 4), 'bad WHD header'
    out = []
    o = 0x10
    while o + 48 <= len(d) and struct.unpack_from('<I', d, o)[0] == 6:
        e = struct.unpack_from('<12I', d, o)
        out.append(dict(index=len(out), fmt=e[2] & 0xffff, flags=e[2] & 0xffff0000,
                        streamed=bool(e[2] & 0x80000000), rate=e[3], bits=e[4],
                        pcmBytes=e[5], dataBytes=e[6], channels=e[7], offset=e[8],
                        frames=e[9], blockAlign=e[10], spb=e[11]))
        o += 48
    assert d[o:] == b'\0' * 8, 'unexpected WHD trailer'
    return out

def ima_block(blk, ch):
    out = []
    pred = [0]*ch; idx = [0]*ch
    for c in range(ch):
        pred[c], idx[c] = struct.unpack_from('<hB', blk, 4*c)[:2]
        out.append([pred[c]])
    p = 4*ch
    while p + 4*ch <= len(blk):
        for c in range(ch):
            for byte in blk[p+4*c:p+4*c+4]:
                for nib in (byte & 15, byte >> 4):
                    s = STEP[idx[c]]
                    diff = s >> 3
                    if nib & 1: diff += s >> 2
                    if nib & 2: diff += s >> 1
                    if nib & 4: diff += s
                    pred[c] += -diff if nib & 8 else diff
                    pred[c] = max(-32768, min(32767, pred[c]))
                    idx[c] = max(0, min(88, idx[c] + IDX[nib & 7]))
                    out[c].append(pred[c])
        p += 4*ch
    return out

def decode(e, bank):
    raw = bank[e['offset']:e['offset'] + e['dataBytes']]
    if e['fmt'] == 1:
        return raw[:e['frames'] * 2 * e['channels']]
    if e['fmt'] != 0x11:
        raise ValueError('format 0x%x not supported' % e['fmt'])
    ch = e['channels']; pcm = array.array('h')
    for b in range(0, len(raw), e['blockAlign']):
        chans = ima_block(raw[b:b + e['blockAlign']], ch)
        for i in range(len(chans[0])):
            for c in range(ch): pcm.append(chans[c][i])
    return pcm[:e['frames'] * ch].tobytes()

def snd_names(d):
    import re
    names = {}
    for m in re.finditer(rb'([A-Za-z0-9_\- ]+)\.wav\x00', d):
        p = m.end()
        one, _, whdoff, _dur = struct.unpack_from('<IIIf', d, p)
        if one == 1 and (whdoff - 1 - 0x10) % 48 == 0:
            names[(whdoff - 1 - 0x10) // 48] = m.group(1).decode()
    return names

def main():
    whd, bank, outdir = sys.argv[1:4]
    streams = sys.argv[4] if len(sys.argv) > 4 else None
    names = snd_names(open(sys.argv[5], 'rb').read()) if len(sys.argv) > 5 else {}
    entries = parse_whd(open(whd, 'rb').read())
    bankd = open(bank, 'rb').read()
    sd = open(streams, 'rb').read() if streams else None
    os.makedirs(outdir, exist_ok=True)
    done = skipped = 0
    for e in entries:
        src = sd if e['streamed'] else bankd
        if src is None or e['offset'] + e['dataBytes'] > len(src) or e['fmt'] not in (1, 0x11, 0x1000):
            skipped += 1; continue
        base = os.path.join(outdir, '%04d_%s' % (e['index'], names.get(e['index'], 'unnamed')))
        if e['fmt'] == 0x1000:
            ogg = src[e['offset']:e['offset'] + e['dataBytes']]
            assert ogg[:4] == b'OggS', 'entry %d: expected Ogg' % e['index']
            open(base + '.ogg', 'wb').write(ogg); done += 1; continue
        pcm = decode(e, src)
        with wave.open(base + '.wav', 'wb') as w:
            w.setnchannels(e['channels']); w.setsampwidth(2); w.setframerate(e['rate']); w.writeframes(pcm)
        done += 1
    print('entries', len(entries), 'decoded', done, 'skipped', skipped)

if __name__ == '__main__':
    main()
