"""specs_s997.py - area 53 (residue 10/11 remainder), batch 997: ZActorIf::ReplaceMove (0x507c60). The id helper 0x5003d0 (thiscall, one
argument k) is a machine-code stub that returns the cell for k; the global function pointer at 0x676414 (cdecl, two arguments) is a
machine-code stub that returns per string (the four strings take random values); the debug channel's cdecl slot 0x2c is a counting stub
that skips its fourth argument (the three-argument prints leave it unset); the hook at 0x7003b0 is set (its null branch is an int3)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def cstub_skip(c, nargs, skip=()):
    rec = c.emu.alloc(4 * (nargs + 1), 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    code += b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def fstub(c, vals):
    # cdecl(esi, string): returns vals[i] for strings 68ac54, 68ac5c, 69d064, 69d06c (i = 0..3)
    keys = [0x68ac54, 0x68ac5c, 0x69d064]
    blocks = []
    body = b'\x8b\x44\x24\x08'                     # mov eax,[esp+8]  (the string)
    # each test: cmp eax,key; jne next; mov eax,val; ret ; (next)
    parts = []
    for i, k in enumerate(keys):
        test = b'\x3d' + struct.pack('<I', k)       # cmp eax,k      (5 bytes)
        ret = b'\xb8' + struct.pack('<I', vals[i] & 0xffffffff) + b'\xc3'   # mov eax,val; ret (6 bytes)
        parts.append((test, ret))
    last = b'\xb8' + struct.pack('<I', vals[3] & 0xffffffff) + b'\xc3'
    # layout: body, then for each: test(5) + jne(2) + ret(6); jne jumps over its ret
    code = body
    for test, ret in parts:
        code += test + b'\x75' + bytes([len(ret)]) + ret
    code += last
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def idstub(c, cells):
    table = c.emu.alloc(4 * len(cells), 4)
    for i, cell in enumerate(cells):
        c.emu.w32(table + 4 * i, cell)
    code = (b'\x8b\x44\x24\x04'                                    # mov eax,[esp+4]  (k)
            + b'\x8b\x04\x85' + struct.pack('<I', table)           # mov eax,[table+eax*4]
            + b'\xc2\x04\x00')                                     # ret 4 (thiscall, one argument)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def cell(c, e, dword):
    x = c.emu.alloc(8, 4)
    c.emu.w32(x, dword)
    c.emu.wbytes(x + 4, bytes([e]))
    return x


def g(c):
    cells = []
    objs = []
    for k in range(2):
        e = c.rng.choice([3, 4, 5])
        if e == 4:
            o = obj(c, 0x40, {0x34: _stub(c, 0, ret=r32(c))})
            objs.append(o)
            cells.append(cell(c, e, o))
        else:
            cells.append(cell(c, e, r32(c)))
    v = c.rng.randint(-3, 5) if c.rng.random() < 0.8 else 0
    cells.append(cell(c, 0, v & 0xffffffff))
    ss.patch(c, 0x5003d0, idstub(c, cells))
    c.emu.w32(0x676414, fstub(c, [c.rng.choice([0, 1]), c.rng.choice([0, 1]), c.rng.choice([0, 1]), c.rng.choice([0, 1])]))
    c.emu.w32(0x7003b0, ss.rec(c, 0))
    ch = obj(c, 0x40, {0x2c: cstub_skip(c, 4, skip=(3,)), 0x30: cstub_skip(c, 4, skip=(3,))})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    A = obj(c, 0x40, {0x598: _stub(c, 1, ret=r32(c)), 0x5c4: _stub(c, 1, ret=r32(c)),
                      0x5c8: _stub(c, 1, ret=r32(c)), 0x5b4: _stub(c, 4)})
    rm = obj(c, 0x100)
    c.emu.w32(rm + 0x44, r32(c))
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x100)
    c.emu.w32(t + 0x18, A)
    p = obj(c, 0x40)
    q = obj(c, 0x40)
    c.emu.w32(p + 4, q)
    return [t, p]


S(0x507c60, 'ZActorIf::ReplaceMove', 'thiscall', gen=g)
