#!/usr/bin/env python3
"""mini_ld.py - tiny static linker for i386 ELF relocatable objects (stand-in for ld.lld on a Mac).

Apple clang can emit i386 ELF objects (--target=i686-linux-gnu) but the Mac has no ld.lld,
llvm-nm or llvm-objcopy. This script does what build.sh needs from them, and nothing more:

    mini_ld.py --base 0x31000000 -o build/pilot.bin --syms build/pilot.syms a.o b.o ...

  * lays out every allocated section (.text*, then read-only data, then .data*, then .bss*/COMMON)
    from 0x31000000, in object order, each at its own alignment;
  * resolves symbols: definitions in the objects first (first global/weak definition wins, so
    duplicate COMDAT copies of inline functions are harmless), then `ext_<hex>` names to that PC
    address of Freedom.Exe (the callee runs as original code);
  * applies R_386_32 (S+A) and R_386_PC32 / R_386_PLT32 (S+A-P) relocations (REL, implicit addend);
  * writes the flat image (bss included as zeros) and an nm-style symbol list "addr T name".

Anything else (an unknown relocation type, an unresolved symbol) stops with a message.
Written 2026-10-11 by the ladder thread (docs/20-ladder.md).
"""
import argparse
import re
import struct
import sys

SHT_PROGBITS, SHT_SYMTAB, SHT_NOBITS, SHT_REL, SHT_RELA = 1, 2, 8, 9, 4
SHF_WRITE, SHF_ALLOC, SHF_EXEC = 1, 2, 4
SHN_UNDEF, SHN_ABS, SHN_COMMON = 0, 0xfff1, 0xfff2


class Obj:
    def __init__(self, path):
        self.path = path
        d = self.d = open(path, 'rb').read()
        if d[:4] != b'\x7fELF' or d[4] != 1 or d[18] != 3:
            raise SystemExit('%s: not an i386 ELF32 object' % path)
        shoff = struct.unpack_from('<I', d, 0x20)[0]
        shnum, shstrndx = struct.unpack_from('<HH', d, 0x30)
        self.sh = []
        for i in range(shnum):
            self.sh.append(struct.unpack_from('<10I', d, shoff + 40 * i))
        strsec = self.sh[shstrndx]
        self.names = [self._str(strsec, s[0]) for s in self.sh]
        self.addr = {}            # section index -> final address
        self.syms = []            # (name, value, size, bind, type, shndx)
        for i, s in enumerate(self.sh):
            if s[1] == SHT_SYMTAB:
                strtab = self.sh[s[6]]
                for k in range(s[5] // 16):
                    nm, val, size, info, other, shndx = struct.unpack_from('<IIIBBH', d, s[4] + 16 * k)
                    self.syms.append((self._str(strtab, nm), val, size, info >> 4, info & 0xf, shndx))

    def _str(self, sec, off):
        o = sec[4] + off
        e = self.d.index(b'\0', o)
        return self.d[o:e].decode()


def kind(name, s):
    flags, typ = s[2], s[1]
    if not flags & SHF_ALLOC or typ not in (SHT_PROGBITS, SHT_NOBITS):
        return None
    if flags & SHF_EXEC:
        return 0
    if typ == SHT_NOBITS:
        return 3
    return 2 if flags & SHF_WRITE else 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('objs', nargs='+')
    ap.add_argument('--base', type=lambda x: int(x, 0), default=0x31000000)
    ap.add_argument('-o', required=True)
    ap.add_argument('--syms', required=True)
    a = ap.parse_args()
    objs = [Obj(p) for p in a.objs]
    # ---- layout
    addr = a.base
    for k in range(4):
        for o in objs:
            for i, s in enumerate(o.sh):
                if kind(o.names[i], s) == k:
                    al = max(s[8], 1)
                    addr = (addr + al - 1) & ~(al - 1)
                    o.addr[i] = addr
                    addr += s[5]
    commons = {}
    for o in objs:
        for nm, val, size, bind, typ, shndx in o.syms:
            if shndx == SHN_COMMON and nm not in commons:
                al = max(val, 1)
                addr = (addr + al - 1) & ~(al - 1)
                commons[nm] = addr
                addr += size
    end = addr
    img = bytearray(end - a.base)
    for o in objs:
        for i, at in o.addr.items():
            s = o.sh[i]
            if s[1] == SHT_PROGBITS:
                img[at - a.base:at - a.base + s[5]] = o.d[s[4]:s[4] + s[5]]
    # ---- symbols
    glob = dict(commons)
    out_syms = []
    for o in objs:
        for nm, val, size, bind, typ, shndx in o.syms:
            if shndx in (SHN_UNDEF, SHN_COMMON) or typ in (3, 4):   # section / file symbols
                continue
            if shndx == SHN_ABS:
                v = val
            elif shndx in o.addr:
                v = o.addr[shndx] + val
            else:
                continue
            if bind in (1, 2):
                if nm not in glob:
                    glob[nm] = v
                    out_syms.append((v, 'T', nm))
            elif nm:
                out_syms.append((v, 't', nm))
    for nm, v in commons.items():
        out_syms.append((v, 'B', nm))

    def resolve(o, k):
        nm, val, size, bind, typ, shndx = o.syms[k]
        if typ == 3:      # section symbol
            return o.addr[shndx]
        if shndx not in (SHN_UNDEF, SHN_COMMON) and bind == 0:
            return val if shndx == SHN_ABS else o.addr[shndx] + val
        if nm in glob:
            return glob[nm]
        m = re.match(r'ext_([0-9a-f]+)', nm)
        if m:
            return int(m.group(1), 16)
        raise SystemExit('%s: unresolved symbol %s' % (o.path, nm))
    # ---- relocations
    for o in objs:
        for i, s in enumerate(o.sh):
            if s[1] == SHT_RELA:
                raise SystemExit('%s: RELA sections not supported' % o.path)
            if s[1] != SHT_REL or s[7] not in o.addr:
                continue
            base = o.addr[s[7]]
            for k in range(s[5] // 8):
                off, info = struct.unpack_from('<II', o.d, s[4] + 8 * k)
                t, sym = info & 0xff, info >> 8
                P = base + off
                S = resolve(o, sym)
                A = struct.unpack_from('<i', img, P - a.base)[0]
                if t == 1:
                    v = S + A
                elif t in (2, 4):
                    v = S + A - P
                else:
                    raise SystemExit('%s: relocation type %d not supported (section %s)' % (o.path, t, o.names[s[7]]))
                struct.pack_into('<I', img, P - a.base, v & 0xffffffff)
    open(a.o, 'wb').write(bytes(img))
    with open(a.syms, 'w') as f:
        for v, t, nm in sorted(out_syms):
            f.write('%08x %s %s\n' % (v, t, nm))
    npc = sum(1 for _, _, nm in out_syms if nm.startswith('pc_'))
    print('built %d registered functions, %d bytes' % (npc, len(img)))


if __name__ == '__main__':
    main()
